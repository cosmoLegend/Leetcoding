class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<int , int> mpp ;
        int n = s.size() ;
        int l = 0 ;
        int maxLen = 0 , len = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(mpp.find(s[i]) == mpp.end()) {
                mpp[s[i]] = 1 ;
                // len ++ ;
                maxLen = max(maxLen , i - l + 1) ;
            }
            else {
                    while(s[l] != s[i]) mpp.erase(s[l]) , l++ ;
                    mpp[s[l]] = 1 ;
                    l++ ;
                    
                }
                // mpp[s[i]] = 1 ;
            }
        


        return max(maxLen , len) ;
        
    }
};