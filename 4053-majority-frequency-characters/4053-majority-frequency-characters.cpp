class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int n = s.size() ;

        vector<int>v(26 , 0) ;

        for (int i = 0 ; i < n ; i++){
            v[s[i] - 'a'] ++ ;
        }

        vector<vector<int>>grpsz(101) ;

        for (int i = 0 ; i < 26 ; i++){
            grpsz[v[i]].push_back(i) ;
        }

        int maxGrpsz = 0 , store = -1 ;

        for (int i = 1 ; i < 101 ; i++){
            if(grpsz[i].size() >= maxGrpsz){
                maxGrpsz = grpsz[i].size() ;
                store = i ; 
            }
        }

        string res = "" ;

        for(int j = 0 ; j < maxGrpsz ; j++){
            res += grpsz[store][j] + 'a' ;
        }

        return res ;

        
    }
};