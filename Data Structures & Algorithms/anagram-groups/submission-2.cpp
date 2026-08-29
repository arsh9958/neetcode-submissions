class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (auto& s : strs) {
            int count[26] = {0};
            for (char c : s) {
                count[c - 'a']++;
            }

            // build a signature string from the counts, e.g. "1#0#0#...#1" for 26 letters
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";  // '#' separates counts so 1,11 vs 11,1 don't collide
            }

            res[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};