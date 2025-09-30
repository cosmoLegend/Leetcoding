class Solution {
public:
    int triangularSum(vector<int>& nums) {
       // int n = nums.size() ;

        vector<int> v= nums ;
        int n = nums.size() ;

        while(n > 1){
        for (int i = 0 ; i < n - 1 ; i++){
            v[i] = nums[i] + nums[i + 1] ;
            v[i] %= 10 ;
        }
        v.pop_back() ;
        n = v.size() ;
        nums = v ;
        }

        return v.back() ;
        
    }
};