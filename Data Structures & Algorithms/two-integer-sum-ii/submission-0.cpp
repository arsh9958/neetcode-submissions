class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>nums;
        for(int i=0;i<numbers.size()-1;i++){
            for(int j=i+1;j<numbers.size();j++){
                if(numbers[i]+numbers[j]==target){
                    nums.push_back(i + 1);
                    nums.push_back(j + 1);
                    return nums;
                }
            }
        }return nums;
    }
};
