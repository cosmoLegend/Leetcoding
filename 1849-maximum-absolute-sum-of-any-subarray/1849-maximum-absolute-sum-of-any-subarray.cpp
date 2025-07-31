// use kadane algo twice 

class Solution {
public:
    int kadane(vector<int> & nums){
        int result = 0 ;
        int cur = 0 ;

        for (int i = 0 ; i < nums.size() ; i++){
            result = max(cur , result) ;
            cur += nums[i] ;
            if(cur > 0) continue ;
            else result = max(result , cur) , cur = 0 ;

        }

        return max(cur, result) ;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size() ; 

        // vector<vector<int>>dp (n + 1 , vector<int> (n + 1 , 0)) ;

        int ans1 = kadane(nums) ;
        
        for (int i = 0 ; i < n ; i++){
            nums[i] = -nums[i] ;
        }

        
        int ans2 = kadane(nums) ;

        return max(ans1 , ans2);


        // for (int i = 0 ; i < n ; i++){
        //     for (int j = 0 ; j < n ; j ++){
        //         if (j < i) continue ;
        //         else if (i == j) dp[i][j] = nums[i] , maxResult = max(abs(dp[i][j]) , maxResult);
        //         else {
        //             dp [i][j] = dp[i][j - 1] + nums[j] ;
        //             maxResult = max(maxResult , abs(dp[i][j]));
        //         }
                
        //     }
        // }
        //     return maxResult ;  

        // return maxResult ;

    }
    
};