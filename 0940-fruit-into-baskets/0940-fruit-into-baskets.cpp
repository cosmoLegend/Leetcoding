class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size() ;

        int l = 0 , r = 0 ;

        int maxLen = 0 ;

        unordered_map<int , int > mpp ; 


        while (r < n){
            mpp[fruits[r]] ++;

            if(mpp.size() <= 2) maxLen = max (maxLen  , r - l + 1) ; 

            else {
                mpp[fruits[l]] -- ;
                if(mpp[fruits[l]] == 0)
                mpp.erase(fruits[l]) ;
                l ++ ;
                maxLen = max(maxLen , r - l + 1) ;
            }

            
         r++ ;
            
        }


        // unordered_map <int , int > mpp ;

        // for (auto &i : fruits){
        //     mpp[i] ++;
        // }

        // int max1 = 0 , max2 = 0 ;
        // for (auto &i : mpp){
        //     if(i.second >= max1) max2 = max1  , max1 = i.second ;
        //     else if (i.second < max1 && i.second >= max2) max2 = i.second ;
        // }

        // return max1 + max2 ;


        return maxLen ;
        
    }
};