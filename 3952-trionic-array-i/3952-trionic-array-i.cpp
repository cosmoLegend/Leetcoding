class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = -1, q = -1;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i]<nums[i+1]) p = i+1;
            else break;
        }
        if(p==-1 || p==0) return false;
        for(int i=p; i<nums.size()-1; i++) {
            if(nums[i]>nums[i+1]) q = i+1;
            else break;
        }
        if(q==-1 || q==nums.size()-1) return false;
        if(p>=q) return false;
        for(int i=q; i<nums.size()-1; i++) {
            if(nums[i]<nums[i+1]) continue;
            return false;
        }
        return true;
    }
};