class Solution {
public:
    vector<int> getRow(int rowIndex) {

       vector<int>ans ;
       ans.push_back(1) ;
       long long first = 1 ;

       // nck = nc(k-1) * (n - k + 1) / k ;

       for (int col = 1 ; col <= rowIndex ; col++){
            first = (first * (rowIndex - col + 1) / col) ;
            ans.push_back((int)first) ;
       }    

       return ans ;
        
    }
};