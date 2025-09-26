class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int n = prices.size() ;
        if(n == 1) return 0 ;
        int maxProfit = 0 , best = 0 , temp = prices[0] ;

        for(int i = 1 ; i < prices.size() ; i++){

            if(prices[i] >prices[i - 1]) best = max (best , prices[i] - temp) ;

            else maxProfit += best , temp = prices[i] , best = 0 ; 
            
            
        }

        if(prices[n - 1] > prices[n - 2]) maxProfit += best ;


        return maxProfit;
    }
};