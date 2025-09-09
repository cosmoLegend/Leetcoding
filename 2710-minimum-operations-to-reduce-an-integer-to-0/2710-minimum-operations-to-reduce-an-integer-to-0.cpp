class Solution {
public:
    int minOperations(int n) {
        long long x = n;   // use wider type to avoid overflow when we do x++
        int ans = 0;
        while (x > 0) {
            if ((x & 3) == 3) {    // trailing bits ..11 → better to add 1
                x++;
                ans++;
            } else if (x & 1) {    // trailing bit 1 → subtract 1
                x--;
                ans++;
            } else {               // trailing bit 0 → shift (no counted op)
                x >>= 1;
            }
        }
        return ans;
    }
};
