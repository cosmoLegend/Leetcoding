class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7 ;

        int n = nums.size() ;
        int q = queries.size() ;
        int m = queries[0].size() ;

        for (auto &q : queries){
            int l = q[0] ;
            int r = q[1] ;
            int k = q[2] ;
            int v = q[3] ;

            while (l <= r){
                nums[l] = (1ll * nums[l] * v) % MOD ;
                l += k ;
            }



        }

        int total = 0 ;

        for (auto &it : nums){
            total ^= it ;
        }

        return total ;

        
    }
};