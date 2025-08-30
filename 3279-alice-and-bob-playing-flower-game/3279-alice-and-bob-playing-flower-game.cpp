class Solution {
public:
    long long flowerGame(int n, int m) {
        
        long long ans = 0 ;

        ans = 1ll * n / 2 * ((m + 1)/ 2) + 1ll *  m / 2 * ((n + 1) / 2) ;

        return ans ;
    }
};