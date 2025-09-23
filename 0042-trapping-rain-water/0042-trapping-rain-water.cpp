class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;

        int maxArea = 0 ; 

        vector<int>pref(n , 0) , suff(n , 0) ;
        pref[0] = height[0] ;
        suff[n - 1] = height[n - 1] ; 

        for (int i = 1 ; i < n ; i++){
            pref[i] = max(height[i] , pref[i - 1]) ; 
        }

        for (int i = n - 2 ; i >= 0 ; i--){
            suff[i] = max(height[i] , suff[i + 1]) ;
        }

        // int area = 0 ;

        for (int i = 0 ; i < n ; i++){
            // if (pref[i] == height[i] || suff[i] == height[i])  maxArea = max(area , maxArea) , area = 0 ;

            maxArea += min(pref[i] , suff[i]) - height[i] ;

        }




        return maxArea ;
        
    }
};