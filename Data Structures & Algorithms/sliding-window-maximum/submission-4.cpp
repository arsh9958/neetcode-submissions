class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> result;
        deque<int> dq;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Remove smaller elements
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(right);

            // Remove elements outside the window
            if (dq.front() < left) {
                dq.pop_front();
            }

            // Window size = k
            if (right - left + 1 == k) {

                result.push_back(nums[dq.front()]);

                left++;
            }
        }

        return result;
    }
};