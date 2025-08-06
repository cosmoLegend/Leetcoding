class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size() ;
        unordered_map <int , int > mpp ;
        vector<int>res (2 , 0);

        for (int i = 0 ; i < n ; i ++){
            int num = nums[i] ;
            int rem = target - nums[i] ;
            if(mpp.find(rem) != mpp.end()) res[0] = mpp[rem] , res[1] = i ;

            mpp[num] = i ;
        }

        return res ;
        
    }
};