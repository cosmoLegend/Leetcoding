class Solution {
public:
    int solve(int idx, vector<int>& vals, unordered_map<int,int>& freq, vector<int>& dp) {
        if (idx >= vals.size()) return 0;
        if (dp[idx] != -1) return dp[idx];

        // Take current
        int take = vals[idx] * freq[vals[idx]];
        int nextIdx = idx + 1;
        if (nextIdx < vals.size() && vals[nextIdx] == vals[idx] + 1) {
            take += solve(idx + 2, vals, freq, dp); // skip neighbor
        } else {
            take += solve(idx + 1, vals, freq, dp);
        }

        // Not take
        int notTake = solve(idx + 1, vals, freq, dp);

        return dp[idx] = max(take, notTake);
    }

    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        // unique sorted values
        vector<int> vals;
        for (auto &p : freq) vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        vector<int> dp(vals.size(), -1);
        return solve(0, vals, freq, dp);
    }
};
