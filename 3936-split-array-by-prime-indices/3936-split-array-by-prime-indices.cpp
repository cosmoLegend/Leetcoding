class Solution {
public:
    using ll = long long;

    static vector<bool> isPrime;
    static bool computed;

    static void sieve(int k) {
        isPrime.assign(k + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= k; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= k; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        computed = true;
    }

    ll splitArray(vector<int>& nums) {
        if (!computed) sieve(1e5);  // ✅ ensures prime list is ready

        ll a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime[i]) a += nums[i];
            else b += nums[i];
        }
        return abs(a - b);
    }
};

// Static member definitions outside the class:
vector<bool> Solution::isPrime;
bool Solution::computed = false;
