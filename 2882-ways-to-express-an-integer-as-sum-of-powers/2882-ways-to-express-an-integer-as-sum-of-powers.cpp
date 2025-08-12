class Solution {
public:
    const int modi = 1e9 + 7 ; 

    int solve(int n , int x , int idx , int ans , vector<vector<int>>&dp) {
        if (ans > n) return 0 ;
        if (ans == n) return 1 ;

        if (dp[idx][ans] != -1) return dp[idx][ans] ;

        int res = 0 ;

        for (int i = idx ; i <= n ; i++){
            long long val = pow(i , x) ;
            if (ans + val > n) break ;
            res = (res + solve (n , x , i + 1 , ans + val , dp)) % modi ;       
            
        }

        return dp[idx][ans] = res % modi ;

    }

    int numberOfWays(int n, int x) {
        int ans = 0 ;
        vector<vector<int>>dp (n + 1 , vector<int>(n + 1 , -1)) ;
        ans = solve (n , x , 1 , 0 , dp) ;
        return ans % modi ;
    }
};