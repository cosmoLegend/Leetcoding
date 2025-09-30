class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {

        int n = values.size() ;
        if(n == 3) return values[0] * values[1] * values[2] ;

        int totalTriangles = n - 2 ;

        int minScore = INT_MAX ;


        vector<vector<int>>dp(n , vector<int>(n , 0)) ;
       // for (int i = 0 ; i < 3 ; i++) dp[i] = 0 ;
        
        for (int i = 3 ; i <= n ; i++){
            for(int j = 0 ; j + i - 1 < n ; j++){
                int k = i + j - 1 ;
                dp[j][k] = INT_MAX ;
                for(int l = j + 1 ; l < k ; l++) {
                    int cost = dp[j][l] + dp[l][k] + values[j] * values[k] * values[l] ;
                    dp[j][k] = min(dp[j][k] , cost) ;
                }
            }
        }


        return dp[0][n - 1] ;
        
    }
};