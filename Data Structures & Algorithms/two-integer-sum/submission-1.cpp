class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> res;
int len = nums.size();

for(int i = 0; i < len; i++){
    int result = target - nums[i];

    if(res.find(result) != res.end()){
        return {res[result], i};
    }

    res[nums[i]] = i;   // insert AFTER checking, not before
}

return {};


    }
};
