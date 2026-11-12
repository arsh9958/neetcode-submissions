
class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // Push all treasure chests
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            int i = node.first;
            int j = node.second;

            for(int k = 0; k < 4; k++) {
                int row = i + x[k];
                int col = j + y[k];

                if(row >= 0 && row < n &&
                   col >= 0 && col < m &&
                   grid[row][col] == INT_MAX) {

                    grid[row][col] = grid[i][j] + 1;
                    q.push({row, col});
                }
            }
        }
    }
};
