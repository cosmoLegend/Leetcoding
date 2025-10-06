class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        

        vector<int>v(amount +1 , INT_MAX) ;
        v[0] = 0 ;

        for (int i = 0 ; i < v.size() ; i++){
            for (int j = 0 ; j < coins.size() ; j++){
                if(i < coins[j]) continue ;
                if(v[i - coins[j]] != INT_MAX)
                v[i] = min(v[i] , 1 +  v[i - coins[j]]) ;
            }
        }

        return v[amount] == INT_MAX ? -1 : v[amount] ;
    }
};