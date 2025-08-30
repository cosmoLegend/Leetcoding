class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int m = mat.size() ;
        int n = mat[0].size() ;
        vector<int> ans ;

        int i = 0 , j = 0 ;
        int dir = 0 ;

        // while (i >= 0 && i < m && j >= 0 && j < n){
        //     if (dir == 1){
        //     ans.push_back(mat[i][j]) ;
        //     i -- , j ++ ;
        //     if (i < 0) i = 0 , dir = 0 ;
        //     } 

        //     else if (dir == 0){

        //     }
        // }


        while (j < n){
            vector<int> temp ;
            for (int it = j , ix = 0 ; it >= 0 && ix < m ; it-- , ix++){
                temp.push_back(mat[ix][it]) ;
            }
            if (dir == 1) ans.insert(ans.end() , temp.begin() , temp.end()) , dir = 0 ;
            else {
                reverse(temp.begin() , temp.end()) ;
                ans.insert(ans.end() ,temp.begin() , temp.end()) ;
                dir = 1 ;
            }
            j ++ ;
           
        }

        i = 1 ;

        while (i < m){
            vector<int> temp ;

            for (int it = i , iy = n - 1 ; it < m && iy >= 0 ; it ++ , iy --){
                temp.push_back(mat[it][iy]) ;
            }
            if (dir == 1) ans.insert(ans.end() , temp.begin() , temp.end()) , dir = 0 ;
            else {
                reverse(temp.begin() , temp.end()) ;
                ans.insert(ans.end() ,temp.begin() , temp.end()) ;
                dir = 1 ;
            }
            i ++ ;

        }


        return ans ;

        
    }
};