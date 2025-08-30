class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ; 

        vector<vector<int>>result(n , vector<int>(n , 0)) ;

        for (int j = 1 ; j < n ; j++){
            vector<int> temp ; 
            for (int row = 0 , col = j ; row < n && col < n  ; row ++ , col ++){
                temp .push_back(grid[row][col]) ;
            }

            sort (temp.begin() , temp.end()) ;
            int it = 0 ;
            
            for (int row = 0 , col = j ; row < n && col < n ; row ++ , col ++){
                result [row][col] = temp[it] ;
                it ++ ;
            }

        }

        for (int i = 0 ; i < n ; i++){
            vector<int> temp ;
            for (int row = i , col = 0 ; row < n && col < n ; row ++ , col ++){
                temp.push_back(grid[row][col]) ;
            }
            sort(temp.rbegin(),temp.rend());
            int it = 0 ;

            for (int row = i , col = 0 ; row < n && col < n; row ++ , col ++){
                result[row][col] = temp[it] ;
                it++ ;
            }
        }

        return result;
    }
};