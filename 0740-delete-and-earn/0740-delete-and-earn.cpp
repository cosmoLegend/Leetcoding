class Solution {
public:
    unordered_map<int,int> mpp;   // value -> count
    vector<int> uniq;             // sorted unique values
    vector<array<int,2>> dp;      // dp[idx][available]
    int n;

    int solve(int idx, int available){
        if (idx >= n) return 0;
        if (dp[idx][available] != -1) return dp[idx][available];

        if (!available) {
            // current value was blocked by previous choice -> skip it
            return dp[idx][available] = solve(idx + 1, 1);
        }

        int val = uniq[idx];

        // option 1: skip current
        int skip = solve(idx + 1, 1);

        // option 2: take current => earn val * count[val]
        long long gain = 1LL * val * mpp[val]; // use long long to be safe
        int nextAvailable = 1;
        if (idx + 1 < n && uniq[idx + 1] == val + 1) nextAvailable = 0; // neighbor blocked

        int take = gain + solve(idx + 1, nextAvailable);

        return dp[idx][available] = max(skip, take);
    }

    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        for (int x : nums) mpp[x]++;

        // build sorted unique list
        uniq.clear();
        uniq.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] != uniq.back()) uniq.push_back(nums[i]);

        n = uniq.size();
        dp.assign(n, { -1, -1 });

        return solve(0, 1); // start at idx 0, available = true
    }
};
