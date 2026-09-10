class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O')
            return;

        board[row][col] = '@';

        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        
         m = board.size();
         n = board[0].size();

        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } 
                else if (board[i][j] == '@')
                    board[i][j] = 'O';
            }
        }
    }
};