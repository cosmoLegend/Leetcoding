class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size() ;

        vector<int> total (3 , 0) ;

        for (int i = 0 ; i < n ; i++) total[s[i] - 'a'] ++ ;

        if (total[0] < k || total[1] < k || total[2] < k) return -1 ;

        int win[3] = {0} ;

        int r = 0 , l = 0 , maxLen = -1 ;

        while (r < n){
            win[s[r] - 'a'] ++ ;

            while (total[s[r] - 'a'] - win[s[r] - 'a'] < k){
                win[s[l] - 'a'] -- ;
                l ++ ;
            }

            maxLen = max (maxLen , r - l + 1) ;

            r++ ;
        }

        return n - maxLen ;
        
    }
};