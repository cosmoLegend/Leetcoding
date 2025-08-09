class Solution {
public:
    int check(vector<vector<int>>&matrix , int num){
        int cnt = 0 , c = matrix.size() - 1 , m = matrix[0].size() ;
        for (int r = 0 ; r < m ; r ++){
            while (c >= 0 && matrix[r][c] > num)  c-- ;
            cnt += (c + 1) ;
        }
        return cnt ;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size() ;
        int m = matrix[0].size() ;
        

        int left = matrix[0][0] , right = matrix[m - 1][n - 1] , ans = -1 ;
        while (left <= right){
            int mid = left + (right - left) / 2 ;
            if(check (matrix , mid) >= k){
                ans = mid ;
                right = mid - 1 ;
            }
            else left = mid + 1 ;

        }

        return ans ;
        
    }
};