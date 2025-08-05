class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size() ;


        unordered_map <int , int > mpp ;

        for (auto &i : fruits){
            mpp[i] ++;
        }

        int max1 = 0 , max2 = 0 ;
        for (auto &i : mpp){
            if(i.second >= max1) max2 = max1  , max1 = i.second ;
            else if (i.second < max1 && i.second >= max2) max2 = i.second ;
        }

        return max1 + max2 ;
        
        
    }
};