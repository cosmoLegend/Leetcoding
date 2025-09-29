class Solution {
public:
    int dr[4] = {-1 , 0 , 1 , 0} ;
    int dc[4] = {0 , -1 , 0 , 1} ;
    int n , m ;

    int sumdfs(vector<vector<int>>&grid , int i , int j){
        if(i < 0 || i >= n || j < 0 || j >= m ||  grid[i][j] == 0) return 0 ;
        long sum = 0 ;
        int tmp = grid[i][j] ;
        grid[i][j] = 0 ;
        sum += sumdfs(grid , i , j + 1) ;
        sum += sumdfs(grid , i , j - 1) ;
        sum += sumdfs(grid , i + 1 , j) ;
        sum += sumdfs(grid , i - 1 , j) ;

        return sum + tmp ; 
        
    }

    int countIslands(vector<vector<int>>& grid, int k) {

         n = grid.size() ;
         m = grid[0].size() ;
        long sum = 0 , cnt = 0 ;

        for(int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if(grid[i][j] != 0) {
                    sum += sumdfs(grid , i , j) ;
                    if(sum % k == 0) cnt ++ ;
                    sum = 0 ;
                }
            }
        }

        return cnt ;
        
    }
};