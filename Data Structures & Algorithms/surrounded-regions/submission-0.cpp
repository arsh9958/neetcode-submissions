
class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;

        int m = board[0].size();

        queue<pair<int,int>> q;

        // First and last rows
        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O') {
                board[0][i] = '#';
                q.push({0,i});
            }

            if(board[n-1][i] == 'O') {
                board[n-1][i] = '#';
                q.push({n-1,i});
            }
        }

        // First and last columns
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i,0});
            }

            if(board[i][m-1] == 'O') {
                board[i][m-1] = '#';
                q.push({i,m-1});
            }
        }

        // BFS
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            int i = node.first;
            int j = node.second;

            for(int k = 0; k < 4; k++) {
                int row = i + x[k];
                int col = j + y[k];

                if(isValid(row,col,n,m) &&
                   board[row][col] == 'O') {

                    board[row][col] = '#';
                    q.push({row,col});
                }
            }
        }

        // Convert remaining O to X and restore safe cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
