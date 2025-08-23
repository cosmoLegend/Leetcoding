class Solution {
public:
    int solve (int n , int curr , int paster){
        if (n == curr) return 0 ;
        if (curr > n) return 1e8 ;

        
        int copyPaste = 2 + solve (n, curr * 2 , curr) ;
        int paste = 1 + solve (n , curr + paster , paster) ;

        return min(copyPaste , paste) ;
    }

    int minSteps(int n) {
        if (n == 1) return 0  ;
       

        int ans = solve (n , 1 , 1) ;

        return ans + 1;
        
    }
};