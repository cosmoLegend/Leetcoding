class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const noexcept {
            // simple hash combine
            return hash<long long>()((static_cast<long long>(p.first) << 32) ^
                                     (p.second & 0xffffffffLL));
        }
    };

    int computeX(string& res) {
        int xc = 0;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == 'R')
                xc++;
            else if (res[i] == 'L')
                xc--;
        }

        return xc;
    }

    int computeY(string& res) {
        int yc = 0;

        for (int i = 0; i < res.size(); i++) {
            if (res[i] == 'U')
                yc++;
            else if (res[i] == 'D')
                yc--;
        }

        return yc;
    }

    int distinctPoints(string s, int k) {
        int l = 0, r = 0;
        int n = s.size();

        int xc = 0, yc = 0;
        xc = computeX(s);
        yc = computeY(s);

        unordered_set<pair<int, int> , PairHash> st;

        r = l + k - 1;
        string res = s.substr(l, k);
        int xmod, ymod;
        xmod = computeX(res);
        ymod = computeY(res);
        xc = xc - xmod, yc = yc - ymod;
        st.insert({xc, yc});

        while (r + 1 < n) {

            if (res.size() == k) {
                if (s[l] == 'L')
                    xc--;
                else if (s[l] == 'R')
                    xc++;
                else if (s[l] == 'U')
                    yc++;
                else
                    yc--;

                l++;
            }

            r++;

            if (s[r] == 'L')
                xc++;
            else if (s[r] == 'R')
                xc--;
            else if (s[r] == 'U')
                yc--;
            else
                yc++;

            st.insert({xc, yc});
        }

        return st.size();
    }
};