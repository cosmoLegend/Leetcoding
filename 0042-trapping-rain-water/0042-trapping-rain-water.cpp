class Solution {
public:
    int trap(vector<int>& height) {

        int totalWater = 0 ;
        int n = height.size() ;
        int maxHeight = 0 ;

        vector<int>leftHeight(n) , rightHeight (n) ;
        leftHeight[0] = height[0] , rightHeight[n - 1] = height[n - 1] ;

        for (int i = 1 ; i < n ; i ++){
            leftHeight[i] = max (leftHeight[i - 1] , height[i]) ;
        }

        for (int i = n - 2 ; i >= 0 ; i --){
            rightHeight[i] = max(rightHeight[i + 1] , height[i]) ;
        }

        for (int i = 0 ; i < n ; i ++){
            totalWater += min(leftHeight[i] , rightHeight[i]) - height[i] ;
        }
        
        return totalWater ;
    }
};