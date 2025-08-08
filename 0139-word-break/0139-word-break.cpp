class Solution {
public:
    

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size() ;
        
        unordered_set<string>dict(wordDict.begin() , wordDict.end()) ;

        vector<int>dp(n + 1 , false) ;
        dp[0] = true ;

        for (int i = 1 ; i <= n ; i++){
            for (int j = i - 1 ; j >=0 ; j --){
                if(dp[j] && dict.count(s.substr(j , i - j))){
                    dp[i] = true ;
                    break ;
                }
            }
        }

        return dp[n] ;
        
    }
};