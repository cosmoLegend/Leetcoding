class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size() ;
        if (n == 1) return 0 ;

        int l = 0 , r = 0 , jumps = 0 ;

        while (r < n - 1){
            int farthest = r ;
            while (l <= r){
                farthest = max(farthest , l + nums[l]) ;
                l ++ ;
            }
            r = farthest , jumps ++ ;
        }
        
        return jumps ;
        
    }
};