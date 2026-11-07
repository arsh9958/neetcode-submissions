
class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool isValid(int i, int j, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }

    int dfs(vector<vector<int>>& grid,
            vector<vector<int>>& vis,
            int i, int j, int n, int m) {

        vis[i][j] = 1;

        int area = 1;

        for(int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];

            if(isValid(row, col, n, m) &&
               vis[row][col] == 0 &&
               grid[row][col] == 1) {

                area += dfs(grid, vis, row, col, n, m);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && vis[i][j] == 0) {

                    int area = dfs(grid, vis, i, j, n, m);

                    res = max(res, area);
                }
            }
        }

        return res;
    }
};
