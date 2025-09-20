class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort (nums.begin() , nums.end()) ;
        int n = nums.size() ;

        unordered_map <int ,int > num ;

        for (int i = 0 ; i < n ; i++) num[nums[i]] ++ ;
        int first = 1 ;

        while (true){
            if (num.find(first) == num.end()) return first ;
            first ++ ;
        }
        return first ;
        
    }
};