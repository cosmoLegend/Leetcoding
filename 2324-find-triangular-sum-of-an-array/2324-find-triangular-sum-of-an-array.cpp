class Solution {
public:
    int triangularSum(vector<int>& nums) {

        int n = nums.size() ;
        //vector<int> v = nums ;

        while(nums.size() > 1){
        for (int i = 0 ; i < nums.size() - 1 ; i++){
            nums[i] = nums[i] + nums[i + 1] ;
            nums[i] %= 10 ;
            
        }
        nums.pop_back() ;
        }

        return nums.front() ;
        
    }
};