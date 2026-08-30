class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];

                if (val == '.') continue;  // skip empty cells

                int boxIndex = (r / 3) * 3 + (c / 3);

                // check for duplicates in row, column, and box
                if (rows[r].count(val) || cols[c].count(val) || boxes[boxIndex].count(val)) {
                    return false;
                }

                // no duplicate found — record this value in all three sets
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[boxIndex].insert(val);
            }
        }

        return true;
    }
};