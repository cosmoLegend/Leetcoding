class Solution {
public:
    bool isActive(string s , vector<int> &order ,int num , int k , int n){
        for (int i = 0 ; i <= num ; i++){
            s[order[i]] = '*' ;
        }
        
        long long total = 0 , runningLength = 0 ;

        for (int i = 0 ; i < n ; i++){
            if(s[i] != '*') runningLength++ ;
            else total += (runningLength * (runningLength + 1)) / 2 , runningLength = 0 ;

        }
        long long ans = runningLength == 0 ? total : total + (runningLength * (runningLength + 1)) /2 ;
        return (1LL * n * (n + 1)) / 2 - ans >= k;

    }

    int minTime(string s, vector<int>& order, int k) {
        int n = s.length() ;

        int left = 0 , right = n - 1 ;

        while (left <= right){
            int mid = left + (right - left)/ 2 ;
            if(isActive(s , order , mid , k , n)) right = mid - 1 ;
            else left = mid + 1 ;
        }
        
        return left == n ? -1 : left ;

    }
};