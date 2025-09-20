class Solution {
public:
    string smallestSubsequence(string s) {

        int n = s.size() ;
        stack<char>st ;
        vector<int>vis(26 , 0) , cnt (26 , 0) ;

        for (int i = 0 ; i < n ; i++){
            cnt[s[i] - 'a'] ++ ;
        }

        for (int i = 0 ; i < n ; i++){
            cnt [s[i] - 'a'] -- ;

            if (!vis[s[i] - 'a']){
                while (!st.empty() && cnt[st.top() - 'a'] > 0 && s[i] < st.top()){
                    vis[st.top() - 'a'] = 0 ; 
                    st.pop() ;
                }

                st.push(s[i]) ;
                vis[s[i] - 'a'] = 1 ;
            }
        }

        string result = "" ;

        while (!st.empty()){
            result += st.top() ;
            st.pop() ;
        }

        reverse(result.begin() , result.end()) ;

        return result ;
        
        
    }
};