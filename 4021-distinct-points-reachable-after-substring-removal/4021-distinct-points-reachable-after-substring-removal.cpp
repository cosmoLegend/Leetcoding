class Solution {
public:
    int computeX(string &res){
        int xc = 0 ;
        for (int i = 0 ; i < res.size() ; i++){    
            if (res[i] == 'R') xc ++ ;
            else if(res[i] == 'L') xc -- ;
        }

        return xc ;
    }

    int computeY(string &res){
        int yc = 0 ;

        for (int i = 0 ; i < res.size() ; i++){
            if(res[i] == 'U') yc ++ ;
            else if(res[i] == 'D') yc -- ;
        }

        return yc ;
    }

    int distinctPoints(string s, int k) {
        int l = 0 , r = 0 ;
        int n = s.size() ;

        int xc = 0 , yc = 0 ;
        xc = computeX(s) ;
        yc = computeY(s) ;

        set<pair<int,int>>st ;

         r = l + k - 1 ;
        string res = s.substr(l , k) ;
        int xmod , ymod ; 
        xmod = computeX(res) ;
        ymod = computeY(res) ;
        xc = xc - xmod , yc = yc - ymod ;
        st.insert({xc , yc}) ;
       

        while(r < n){
            
           if(res.size() == k){
                if(s[l] == 'L') xc -- ;
                else if(s[l] == 'R') xc ++ ;
                else if (s[l] == 'U') yc ++ ;
                else yc -- ;

                l++ ;
           }

           r ++ ;
           if(r < n){

                if(s[l] == 'L') xc ++ ;
                else if(s[l] == 'R') xc -- ;
                else if (s[l] == 'U') yc -- ;
                else yc ++ ;

                st.insert({xc , yc}) ;
                
           }

        
        }

        return st.size() ;
        
    }
};