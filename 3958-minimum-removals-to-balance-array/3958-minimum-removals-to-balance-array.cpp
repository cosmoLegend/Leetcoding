class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size() ;
        if(n == 1) return 0 ;
        sort(nums.begin() , nums.end()) ;
        int cnt = 0 , minRemovals = INT_MAX , j = 1; 

        for (int i = 0 ; i < n - 1 ; i ++){
            
            while(j < n && 1ll * nums[i] * k >= nums[j]){
                j ++ ;               
            }
            
            minRemovals = min (minRemovals , n - j + i) ;
            
        }
        return minRemovals ;
    }
};