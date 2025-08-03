class Solution {
    public boolean isTrionic(int[] nums) {
        int p=0;
        int n=nums.length;
        int q=n-1;
        while(p<q){
            if(nums[p]<nums[p+1]){
                p++;
            }else{
                break;
            }
        }
        while(p<q){
            if(nums[q]>nums[q-1]){
                q--;
            }else{
                break;
            }
        }
        for(int i=p;i<q;i++){
            if(nums[i]<=nums[i+1]){
                return false;
            }
        }
        
    
    if(p!=0 && q!=n-1) return true;
        return false;
    }
}