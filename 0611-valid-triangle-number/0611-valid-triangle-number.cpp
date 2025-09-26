class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2)
            return 0;

        sort(nums.begin(), nums.end());
        int cnt = 0;


        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int k = j + 1 ; 
                while (k < n && nums[i] + nums[j] > nums[k]) k++ ;
                cnt += k - j - 1 ;
            }
        }

        
        return cnt;
    }
};