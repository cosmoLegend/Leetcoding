class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n = landStartTime.size(); 
        int m = waterStartTime.size() ;

        int minstartLand = INT_MAX , minstartWater = INT_MAX ;

        for (int i = 0 ; i < n ; i++){
            minstartLand = min(minstartLand, landStartTime[i] + landDuration[i]) ;
        }

        for (int j = 0 ; j < m ; j++){
            minstartWater = min(minstartWater, waterStartTime[j] + waterDuration[j]) ;
        }

        int ans = INT_MAX ;

        for (int i = 0 ; i < n ; i++){
            int check = max(minstartWater , landStartTime[i]) ;
            ans = min(ans , check + landDuration[i]) ;
        }

         for (int j = 0 ; j < m ; j++){
            int check = max(minstartLand , waterStartTime[j]) ;
            ans = min(ans , check + waterDuration[j]) ;
        }

        return ans ;
    }
};