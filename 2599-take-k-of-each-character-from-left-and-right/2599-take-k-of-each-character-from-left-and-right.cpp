class Solution {
public:
    int id(char c) { return c - 'a'; }

    bool possible(int take, string &s, int k, vector<int> &tot) {
        int n = s.size();
        int keep = n - take;
        if (keep < 0) return false;
        
        if (keep == 0) { // remove all characters
            return (tot[0] >= k && tot[1] >= k && tot[2] >= k);
        }

        int win[3] = {0, 0, 0};
        // initial window [0 .. keep-1]
        for (int i = 0; i < keep; i++) win[id(s[i])]++;

        if (tot[0] - win[0] >= k && tot[1] - win[1] >= k && tot[2] - win[2] >= k)
            return true;

        // slide window
        for (int r = keep; r < n; r++) {
            int l = r - keep;
            win[id(s[l])]--;
            win[id(s[r])]++;
            if (tot[0] - win[0] >= k && tot[1] - win[1] >= k && tot[2] - win[2] >= k)
                return true;
        }
        return false;
    }

    int takeCharacters(string s, int k) {
        int n = s.size();
        if (k == 0) return 0;

        vector<int> tot(3, 0);
        for (char c : s) tot[id(c)]++;

        if (tot[0] < k || tot[1] < k || tot[2] < k) return -1;

        int low = 0, high = n, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(mid, s, k, tot)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
