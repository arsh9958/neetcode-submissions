class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0;
        int end = n;

        while(start<end){
            int mid = (start + end)/2;

            if(target>nums[mid]){
                start = mid+1;
            }
            if(target==nums[mid]){
                return mid;
            }
            if(target<nums[mid]){
                end = mid-1;
            }

        }
        return -1;

    }
};
