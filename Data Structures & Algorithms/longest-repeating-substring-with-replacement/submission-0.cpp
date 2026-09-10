class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>res;
        int left  = 0;
        int maxFrequency = 0;
        int ans = 0;

        for(int right = 0;right<s.size();right++){
            res[s[right]]++;
            maxFrequency = max(maxFrequency,res[s[right]]);
            while((right-left+1)-maxFrequency > k){
                res[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
