class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size() ;
        int cnt = 0 ;
        bool forp = false , forq = false , forend = false ;

        for (int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i - 1] && !forq && !forend) forp = true ;

            else if(nums[i] < nums[i - 1] && forp && !forend) forq = true ;

            else if (nums[i] > nums[i - 1] && forp && forq) forend = true ;

            else return false ;
        }


        return forp && forq && forend ;
        
    }
};