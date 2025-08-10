class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int n = arr.size() ;
        int up = 0 , down = 0 , maxLen = 0;

        for (int i = 1 ; i < n ; i++){
            if ((down > 0 && arr[i] > arr[i - 1]) || arr[i] == arr[i - 1]){
                up = 0 , down = 0 ;
            }
            if(arr[i] > arr[i - 1]) up ++ ;
            if(arr[i] < arr[i - 1] && up > 0) down ++ ;
            if(up > 0 && down > 0)
            maxLen = max (maxLen , up + down + 1) ;
        }

       return maxLen ;
        
    }
};