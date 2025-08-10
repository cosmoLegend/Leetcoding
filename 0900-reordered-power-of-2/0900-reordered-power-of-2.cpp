class Solution {
public:
    bool reorderedPowerOf2(int n) {

        vector<int>v(10 , 0) ;
        string st = to_string(n) ;

        for (int i = 0 ; i < st.size() ; i++){
            v[st[i] - '0'] ++ ;
        }

        for (int i = 0 ; i <= 31 ; i++){
            int num = (1 << i) ;
            vector<int>w(10 , 0) ;

            string s = to_string(num) ;
            if(s.size() != st.size()) continue ;

            for (int j = 0 ; j < s.size() ; j++){
                w[s[j] - '0']++ ;
            }

            if (v == w) return true ;
        }

        return false ;

        
    }
};