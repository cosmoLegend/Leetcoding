class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {

        //count total number of strictly decreasing pairs 

        int n = weight.size() ;

        int r = 0 , cnt = 0 ;

        while(r < n - 1){ 
            if(weight[r] > weight[r + 1]) cnt ++ , r += 2 ;

            else r ++ ;

        }

        return cnt ;
        
    }
};