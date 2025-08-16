class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length() ;
        string largest = "" ;


        for (int i = 0 ; i < n - 2 ; ){
            if(num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                largest = max(largest ,num.substr(i , 3)) ;
                i += 3 ;
            }
            else i ++ ;
        }

        return largest ;
        
    }
};