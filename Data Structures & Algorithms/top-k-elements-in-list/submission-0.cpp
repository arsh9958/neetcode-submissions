class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>s;
        
        for(auto&it : nums){
            s[it]++;
        }
    
    vector<pair<int,int>>result;
   
    for(auto& pair :s){
        result.push_back({pair.second,pair.first});
        
    }
    
    sort(result.rbegin(),result.rend());


   vector<int>finaly;
        for(int i = 0;i<k;i++){
            finaly.push_back(result[i].second);
        }
            
    return finaly;
    }
   
  
};
