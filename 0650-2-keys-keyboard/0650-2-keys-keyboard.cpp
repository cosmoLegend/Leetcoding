class Solution {
public:
    int minSteps(int n) {

        int paste = 1 ;
        int copy = 0 ;
        int total = 0 ;

        while (paste != n){
            if (n % paste == 0){
                copy = paste ; 
                total ++ ;
            }

            paste += copy ;
            total ++ ;

        }



        return total ;
        
    }
};