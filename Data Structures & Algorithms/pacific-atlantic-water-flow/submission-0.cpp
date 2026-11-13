
class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    void dfs(int i, int j,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis) {

        int n = heights.size();
        int m = heights[0].size();

        vis[i][j] = 1;

        for(int k = 0; k < 4; k++) {

            int row = i + x[k];
            int col = j + y[k];

            if(row >= 0 && row < n &&
               col >= 0 && col < m &&
               !vis[row][col] &&
               heights[row][col] >= heights[i][j]) {

                dfs(row, col, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        // Pacific: top and left boundaries
        for(int j = 0; j < m; j++) {
            dfs(0, j, heights, pacific);
        }

        for(int i = 0; i < n; i++) {
            dfs(i, 0, heights, pacific);
        }

        // Atlantic: bottom and right boundaries
        for(int j = 0; j < m; j++) {
            dfs(n - 1, j, heights, atlantic);
        }

        for(int i = 0; i < n; i++) {
            dfs(i, m - 1, heights, atlantic);
        }

        // Find common cells
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
