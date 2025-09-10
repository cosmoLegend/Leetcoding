class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> badPeople;
        
        // step 1: collect people in bad friendships
        for (auto &f : friendships) {
            int u = f[0]-1, v = f[1]-1;
            unordered_set<int> s(languages[u].begin(), languages[u].end());
            bool ok = false;
            for (int lang : languages[v]) {
                if (s.count(lang)) { ok = true; break; }
            }
            if (!ok) {
                badPeople.insert(u);
                badPeople.insert(v);
            }
        }
        
        if (badPeople.empty()) return 0; // everyone already ok
        
        // step 2: for each language, count coverage
        vector<int> cnt(n+1, 0);
        int ans = 0 ;
        for (int person : badPeople) {
            for (int lang : languages[person]) {
                cnt[lang]++;
                ans = max (ans , cnt[lang]) ;
            }
        }

        
        // // step 3: minimize teachings
         int total = badPeople.size();
        // int ans = INT_MAX;
        // for (int lang = 1; lang <= n; lang++) {
        //     ans = min(ans, total - cnt[lang]);
        // }
        return total - ans;
    }
};
