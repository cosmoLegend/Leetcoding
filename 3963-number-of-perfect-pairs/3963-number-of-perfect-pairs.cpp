class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size() ;
        long long totalPairs = 0 ;

        for (int i = 0 ; i < n ; i++){
            if(nums[i] < 0)  nums[i] = - nums[i] ;
        }

        sort(nums.begin() , nums.end()) ;

        int l = 0 , r = 0 ;

        while (r < n){
            while (nums[r] > 2 * nums[l]) l ++ ;
            totalPairs += r - l ;
            r++ ;
        }


        return totalPairs ;
    }
};