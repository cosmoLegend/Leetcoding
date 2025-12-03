// basically bs on answers ka question hai 

class Solution {
public:
    using ll = long long ;

    bool isPossible(vector<int> &batteries , ll num , ll n){

        ll target = n * num ; 
        
        for (int i = 0 ; i < batteries.size() ; i++){
            target -= min((ll)batteries[i] , num) ; 
            if(target <= 0) return true ;
           //  else return false ;
        }

        return false ;

    }

    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();

        ll lo = *min_element(batteries.begin() , end(batteries)) ;
        

        ll totalMinutes = 0 ; 

        for (int i = 0 ; i < m ; i ++){
            totalMinutes += batteries[i];
        }

        ll high = totalMinutes / n ;
        ll ans = 0 ; 

        while (lo <= high){
            ll mid = lo + (high - lo) / 2 ; 
            if(isPossible(batteries, mid, n)) {
                ans = mid ;
                lo = mid + 1 ;
            }
            else {
                high = mid - 1 ;
            }

        }

        return ans ;
        
    }
};