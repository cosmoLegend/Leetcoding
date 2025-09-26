class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2)
            return 0;

        sort(nums.begin(), nums.end());
        int cnt = 0;

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int num = nums[i] + nums[j];
                auto it = lower_bound(nums.begin() + (j + 1), nums.end(), num);
                cnt += it - (nums.begin() + (j + 1));
            }
        }

        if (cnt < 0)
            return 0;
        return cnt;
    }
};