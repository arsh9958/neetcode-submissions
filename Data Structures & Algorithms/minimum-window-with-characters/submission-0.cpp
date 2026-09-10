class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int have = 0;

        int bestLength = INT_MAX;
        int bestLeft = 0;

        for (int right = 0; right < s.size(); right++) {

            // ADD right
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                have++;
            }

            // WINDOW IS VALID
            while (have == need.size()) {

                // Save answer
                if (right - left + 1 < bestLength) {
                    bestLength = right - left + 1;
                    bestLeft = left;
                }

                // REMOVE left
                char remove = s[left];
                window[remove]--;

                if (need.count(remove) &&
                    window[remove] < need[remove]) {
                    have--;
                }

                left++;
            }
        }

        if (bestLength == INT_MAX)
            return "";

        return s.substr(bestLeft, bestLength);
    }
};