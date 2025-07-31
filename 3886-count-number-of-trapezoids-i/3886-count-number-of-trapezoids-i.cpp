class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        vector <long long>ans ;

       //  unordered_map <int , vector<int>> yforx ;
        unordered_map <int , vector<int>> xfory ;


        for (vector<int> &i : points){
            
            // yforx[i[0]].push_back(i[1]) ;
            xfory[i[1]].push_back(i[0]) ;

        }

        
        for (auto &mpp : xfory){
            long long n = mpp.second.size() ;
            if (n >= 2) ans .push_back ( n * (n - 1) / 2) ;
        }

        // compute suffix sum 
        
        int m = ans.size() ;

        vector<int>sufArray (m + 1 , 0) ;

        for (int i = m - 2 ; i >= 0 ; i -- ){

            sufArray[i] = sufArray[i + 1] + ans[i + 1] ;

        }

        long long result = 0 ;

        for (int i = 0 ; i < m ; i++){
            result += ans[i] * sufArray[i]  ;
        }

        return result % (long long)(1e9 + 7);
        
    }
};