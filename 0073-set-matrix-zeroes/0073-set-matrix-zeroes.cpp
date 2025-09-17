class Solution {
public:
    const long long wildcard = 1e9 + 1 ;
    void setCol (int idx , vector<vector<int>> & matrix , int m){
        for (int j = 0 ; j < m ; j ++){
            if (matrix[j][idx] != 0)
            matrix[j][idx] = wildcard ;
        }
        return ;
        
    }
    
    void setRow (int idx , vector<vector<int>> & matrix , int n){
        // int n = matrix[0].size() ;
        // int m = matrix.size() ;
        for (int i = 0 ; i < n ; i ++){
            if (matrix[idx][i] != 0)
            matrix[idx][i] = wildcard ;
        }
        // for (int j = 0 ; j < m ; j ++){
        //     matrix[j][idx2] = 0 ;
        // }
        return ;
    }

    void setZeroes(vector<vector<int>>& matrix) {

         int n = matrix[0].size() ;
         int m = matrix.size() ;

        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (matrix[i][j] == 0){
                    setRow (i, matrix , n) ;
                    setCol (j , matrix , m) ;
                    //setCol () ;
                }
            }
        }

        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if(matrix[i][j] == wildcard) matrix[i][j] = 0 ;
            }
        }

        return ; 
        
    }
};