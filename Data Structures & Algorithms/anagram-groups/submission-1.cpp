class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>res;

        for(auto&it : strs){
           string og = it;
           sort(og.begin(),og.end());
           res[og].push_back(it); 
        }

        vector<pair<string,vector<string>>>result;

        for(auto&it : res){
            result.push_back(it);
        }

        vector<vector<string>>finaly;

        for(auto&it : result){
            finaly.push_back(it.second);
        }
        return finaly;
    }
};
