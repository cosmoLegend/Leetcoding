class Solution {
public:
    bool solve (int i , int j , string &p , string &s , vector<vector<int>>& dp){
        //base case

        if (i < 0 && j < 0) return true ;

        if (i < 0 && j >= 0) return false ;

        if (j < 0 && i >= 0){
            for (int m = 0 ; m <= i ; m++){
                if(p[m] != '*') return false ;
            }
            return true ;
        }

        //conditions 
        //1. wildcard 2 . normal

        if(dp[i][j] != -1) return dp[i][j] ;

        if(p[i] == s[j] || p[i] == '?') return dp[i][j] = solve (i - 1 , j - 1 , p , s , dp) ;

        else if(p[i] == '*')
        return dp[i][j] = solve (i - 1 , j , p , s , dp) bitor solve (i , j - 1 , p , s , dp) ;

        return dp[i][j] = false ;

    }

    bool isMatch(string s, string p) {

        int n = s.length() ;
        int m = p.length() ;

        vector<vector<int>>dp(m , vector<int> (n , -1)) ;
        return solve (m - 1 , n - 1 , p , s , dp) ;
        
    }
};