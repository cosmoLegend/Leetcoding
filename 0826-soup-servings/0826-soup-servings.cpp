class Solution {
public:
    double solve (int n , int qa , int qb , vector<vector<double>> & dp){
        if(qa == 0 && qb == 0) return dp[qa][qb] = 0.5 ;
        else if (qa == 0 && qb > 0) return dp[qa][qb] = 1 ;
        else if (qa > 0 && qb == 0) return dp[qa][qb] = 0;

        if(dp[qa][qb] != -1) return dp[qa][qb] ;

        double move1 = 0.25 * solve (n , qa - min(qa , 100) , qb , dp) ;
        double move2 = 0.25 * solve (n , qa - min(qa , 75) , qb - min(qb , 25) , dp) ;
        double move3 = 0.25 * solve (n , qa - min (qa , 50 ) , qb - min(qb , 50) , dp) ;
        double move4 = 0.25 * solve (n , qa - min(qa , 25) , qb - min(qb , 75) , dp) ;

        return dp[qa][qb] = move1 + move2 + move3 + move4 ;
    }

    double soupServings(int n) {
        if (n > 4800) return 1.0 ;

        int qa = n , qb = n ;

        vector<vector<double>>dp(n + 1 , vector<double> (n + 1, -1)) ;

        double prob = solve (n , n , n , dp) ;

        return prob ;
        
    }
};