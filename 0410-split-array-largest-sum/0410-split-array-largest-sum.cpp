class Solution {
public:
    bool check (int num , vector<int> & arr , int k){
        int n = arr.size() ;
        int maxSum = 0 ;
        int totalParts = 1 ; 

        for (int i = 0 ; i < n ; i++){
            maxSum += arr[i] ;

            if (maxSum > num) {

                totalParts ++ ;
                maxSum = arr[i] ;

                if (totalParts > k) return false ;
            }
            
        }

        return true ;

    }

    int splitArray(vector<int>& nums, int k) {

        int n = nums.size() ;

        int low  = *max_element (nums.begin() , nums.end()) , high = accumulate(nums.begin() , nums.end() , 0) ;

        int ans = 0 ;

        while (low <= high) {
            int mid = low + (high - low) / 2 ;

            if (check(mid , nums , k)) ans = mid , high = mid - 1 ;

            else low = mid + 1 ;
        }

        return ans ;
        
    }
};