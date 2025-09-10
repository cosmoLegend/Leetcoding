class Solution {
public:
    int solve (int num , int n , int delay , int forget , vector<int> &dp){
        if (num == 1) return 1 ;
        if (dp[num] != -1) return dp[num] ;
        int result = 0 ; 

        for (int i = num - forget + 1 ; i <= num - delay ; i++){
            if (i > 0){
                result += solve(i , n , delay , forget , dp) ;
            }
        }


        return dp[num] = result ;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 0 ;

        vector<int>dp (n + 1 , -1) ;
        for (int i = n - forget + 1 ; i <= n  ; i++){
            ans += solve (i , n , delay , forget , dp) ;
        }

        return ans ;
    }
};
