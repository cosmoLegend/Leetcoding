class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size() ;
        if (n == 1) return true ;

        bool ans = false ;
        int maxJump = 0 , maxInd = 0 ;
        
        for (int i = 0 ; i < n ; i++){
            if (i > maxInd) return false ;
            maxInd = max(maxInd , i + nums[i]) ; 
            
        }

        return true  ;

    }
};