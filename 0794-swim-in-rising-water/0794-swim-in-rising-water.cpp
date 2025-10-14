#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n; // to store grid size

    bool canReach(vector<vector<int>>& grid, int time) {

        if (grid[0][0] > time) return false;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = 1;

        vector<int> delrc = {1, 0, -1, 0, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row == n - 1 && col == n - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nr = row + delrc[i];
                int nc = col + delrc[i + 1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] <= time) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {

        n = grid.size();

        int lo = grid[0][0];
        int hi = 0;

        for (auto &row : grid)
            for (auto cell : row)
                hi = max(hi, cell);

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (canReach(grid, mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
