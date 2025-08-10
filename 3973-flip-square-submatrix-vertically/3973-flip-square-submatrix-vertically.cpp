class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size() ;
        int n = grid[0].size() ;

       

        for (int i = 0 ; i * 2 < k ; i ++){
            for (int j = 0 ; j < k ; j++){
                swap(grid[x + i][y + j] , grid[x + k - 1 - i][y + j]) ;
            }
        }



        return grid ;
        
    }
};