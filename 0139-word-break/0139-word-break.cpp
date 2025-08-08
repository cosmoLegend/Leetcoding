class Solution {
public:
    bool solve (int idx , string str , unordered_set<string>&dict, vector<int> & dp){

        if (idx == str.size()) return true ;

        if (dp[idx] != -1) return dp[idx] ;

        for (int i = idx ; i < str.size() ; i++){
            string word = str.substr(idx ,i - idx + 1) ;
            if (dict.count(word) && solve(i + 1 , str , dict , dp)) 
            return dp[idx] = true ;
        }
        return dp[idx] = false ;

    }

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size() ;
        
        unordered_set<string>dict(wordDict.begin() , wordDict.end()) ;

        vector<int>dp(n + 1 , -1) ;

        return solve(0 , s , dict , dp) ;
        
    }
};