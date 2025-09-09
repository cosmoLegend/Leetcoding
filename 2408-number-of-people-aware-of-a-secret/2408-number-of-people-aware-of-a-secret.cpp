class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1); // dp[i] = new people who learn on day i
        vector<long long> diff(n + 2); // difference array for sharers

        dp[1] = 1;
        diff[1 + delay] = 1;          // start sharing at this day
        if (1 + forget <= n) diff[1 + forget] = (diff[1 + forget] - 1 + MOD) % MOD;

        long long activeSharers = 0;

        for (int day = 2; day <= n; ++day) {
            activeSharers = (activeSharers + diff[day]) % MOD;
            dp[day] = activeSharers;

            // those who learn today will share later
            if (day + delay <= n) {
                diff[day + delay] = (diff[day + delay] + dp[day]) % MOD;
            }
            if (day + forget <= n) {
                diff[day + forget] = (diff[day + forget] - dp[day] + MOD) % MOD;
            }
        }

        // count people who still remember on day n
        long long ans = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            if (day >= 1) ans = (ans + dp[day]) % MOD;
        }

        return (int)ans;
    }
};
