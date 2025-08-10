class Solution {
public:
    int sortPermutation(vector<int>& nums) {

        int n = nums.size() ;
        int ans = 0 , cnt = 0 ;

        for (int i = 0 ; i < n ; i++){
            if(nums[i] == i) continue ;
            else{
                if (cnt == 0) 
            ans = nums[i] , cnt = 1 ;
            else ans &= nums[i] ;
            }
        }

        return ans ;
        
    }
};