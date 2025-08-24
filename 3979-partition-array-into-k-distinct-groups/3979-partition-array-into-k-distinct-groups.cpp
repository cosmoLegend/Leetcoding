class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map <int , int> mpp ; 
        int n = nums.size() ;

        if (n % k != 0) return false ;

        for (int i = 0 ; i < n ; i++){
            mpp[nums[i]] ++ ;
        }

        vector<pair<int,int>>freqMap ;

        for (auto &i : mpp) freqMap.push_back({i.second ,i.first}) ;

        sort (freqMap.rbegin() , freqMap.rend()) ;

        int groups = n / k ;

        for (int i = 0 ; i < freqMap.size() ; i++){
            if (freqMap[i].first > groups) return false ;
            else n -= freqMap[i].first ;
        }

        if (n == 0) return true ;
        return false ;

    }
};