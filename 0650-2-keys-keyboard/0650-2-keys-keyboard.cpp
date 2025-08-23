class Solution {
public:
    int solve (int n , int curr , int paster, vector<vector<int>>& dp){
        if (n == curr) return 0 ;
        if (curr > n) return 1e8 ;

        if (dp[curr][paster] != -1) return dp[curr][paster] ;

        
        int copyPaste = 2 + solve (n, curr * 2 , curr , dp) ;
        int paste = 1 + solve (n , curr + paster , paster , dp) ;

        return dp[curr][paster] = min(copyPaste , paste) ;
    }

    int minSteps(int n) {
        if (n == 1) return 0  ;
        vector<vector<int>>dp(n + 1 , vector<int> (n + 1 , -1));

        int ans = solve (n , 1 , 1 , dp) ;

        return ans + 1;
        
    }
};