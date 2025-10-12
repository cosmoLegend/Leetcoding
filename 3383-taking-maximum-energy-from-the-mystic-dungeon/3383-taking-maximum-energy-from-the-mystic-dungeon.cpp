class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int n = energy.size() ;
        int maxSum = INT_MIN;

        //suffixes leke ho jayega 
        vector<int>suff(n , 0) ;

        suff[n - 1] = energy[n - 1] ;

        for (int i = n - 1 ; i >= 0 ; i --){
            if (i + k < n) suff[i] = suff[i + k] + energy[i] ;
            else suff[i] = energy[i] ;
            maxSum = max(suff[i] , maxSum) ;

        }

        return maxSum ;
        
    }
};