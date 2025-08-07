class Solution {
public:
    int trap(vector<int>& height) {

        int totalWater = 0 ;
        int n = height.size() ;
        int maxHeight = 0 ;

        int l = 0 , r = n - 1 , leftMax = 0 , rightMax = 0;

        while (l <= r){
            if (height[l] < height[r]){
                leftMax = max(leftMax , height[l]) ;
                totalWater += leftMax - height[l] ;
                l ++ ;
            }
            else {
                rightMax = max(rightMax , height[r]) ;
                totalWater += rightMax - height[r];
                r -- ;
            }
        }
        
        return totalWater ;
    }
};