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
    
   priority_queue<pair<int,int>>pq;
   
   for(auto&it : result){
    pq.push(it);
   }

   vector<int>finaly;
   while(k!=0){
    finaly.push_back(pq.top().second);
    pq.pop();
    k--;
   }

   return finaly;
    }
};
