class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Loop through each cell in the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    // Check row
                    for (int b = 0; b < 9; b++) {
                        if (b != j && board[i][b] == c) {
                            return false;
                        }
                    }
                    // Check column
                    for (int a = 0; a < 9; a++) {
                        if (a != i && board[a][j] == c) {
                            return false;
                        }
                    }
                    // Check 3x3 sub-box
                    int rowStart = (i / 3) * 3;
                    int colStart = (j / 3) * 3;
                    for (int x = rowStart; x < rowStart + 3; x++) {
                        for (int y = colStart; y < colStart + 3; y++) {
                            if ((x != i || y != j) && board[x][y] == c) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
