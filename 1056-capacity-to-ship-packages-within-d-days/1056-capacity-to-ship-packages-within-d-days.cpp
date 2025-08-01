class Solution {
public:
    int helper (vector<int> &weights , int space){
        int days = 1 ;

        int load = 0 ;

        int n = weights.size() ;

        for (int i = 0 ; i < n ; i++){

            load += weights[i] ;

            if(load > space){
                days += 1 ;
                load = weights[i] ;
            }
            
            
        }

        return days ;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element (weights.begin() , weights.end()) ;
        int high = accumulate(begin(weights) , end(weights) , 0) ;

        while (low <= high){
            int mid = low + (high - low) / 2 ;
            int numberOfdays = helper (weights , mid) ;

            if(numberOfdays <= days){
                high = mid - 1 ;
            }

            else {
                low = mid + 1 ;
            }
        }

        return low ;
        
    }
};