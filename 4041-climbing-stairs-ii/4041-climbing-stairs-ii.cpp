class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        int m = costs.size();
        vector<int> dp(m + 1, INT_MAX);
        dp[0] = 0;

        // store input midway & normalize to 1-indexed
        vector<int> tmp(m + 1, 0);
        for (int i = 1; i <= m; ++i)
            tmp[i] = costs[i - 1];

        for (int i = 0; i <= m; i++) { // was: i < m - 3
            if (dp[i] == INT_MAX)
                continue;
            int lim = min(m, i + 3); // was: min(m - 1, i + 3)
            for (int j = i + 1; j <= lim;
                 j++) { // was: j <= i + 3 (ignored lim)
                int d = j - i;
                dp[j] = min(dp[j], dp[i] + tmp[j] + d*d) ;
            }
        }

        return dp[m]; // was: dp[m - 1]
    }
};