class Solution {
public:
    int nextGreaterElement(int n) {

        string s = to_string(n);

        if (next_permutation(s.begin(), s.end())) {
            long long val = stoll(s); // use long long to avoid overflow first
            if (val <= INT_MAX) {
                return (int)val;
            } else {
                return -1; // overflow beyond 32-bit
            }
        }

        // no next permutation exists (digits are in descending order)
        return -1;
    }
};