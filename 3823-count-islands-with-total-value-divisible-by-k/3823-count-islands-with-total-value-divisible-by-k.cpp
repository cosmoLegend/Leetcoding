class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};  // up, left, down, right
    int dc[4] = {0, -1, 0, 1};
    int n, m;

    int sumdfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
            return 0;

        int tmp = grid[i][j];
        grid[i][j] = 0; // mark visited
        long sum = tmp;

        // explore all 4 directions
        for (int d = 0; d < 4; ++d) {
            int ni = i + dr[d];
            int nj = j + dc[d];
            sum += sumdfs(grid, ni, nj);
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) {
                    int islandSum = sumdfs(grid, i, j);
                    if (islandSum % k == 0)
                        cnt++;
                }
            }
        }

        return cnt;
    }
};
