class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size() ;
        vector<int>leftall (n , 1) , rightall (n , 1) ;
        int sum = 0 ;

        //check left neighbours 
        if (n == 1) return 1 ;

        for (int i = 1 ; i < n ; i ++){
            if (ratings [i] > ratings [i - 1]) leftall[i] = leftall[i - 1] + 1 ;
            else leftall[i] = 1 ;
        }

        // check right neighbours ;

        for (int i = n - 2 ; i >= 0 ; i --){
            if (ratings[i] > ratings[i + 1])
            rightall[i] = rightall[i + 1] + 1 ;

            else rightall[i] = 1 ;

        }

        for (int i = 0 ; i < n ; i++){
            sum += max(leftall[i] , rightall[i]) ;
        }
        

        return sum ;
        
    }
};