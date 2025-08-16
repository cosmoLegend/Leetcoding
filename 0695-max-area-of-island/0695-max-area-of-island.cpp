class Solution {
public:
    int dfs (vector<vector<int>>& grid , vector<vector<bool>>& vis , int row , int col , int n , int m ){
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0 || vis[row][col] == 1) return 0 ;

        vis[row][col] = 1 ;
        int total = 1 ;

        total += dfs (grid , vis , row  + 1 , col , n , m) ; 
        total += dfs (grid , vis , row , col + 1 , n , m) ;
        total += dfs (grid , vis , row , col - 1 , n , m) ;
        total += dfs (grid , vis , row - 1 , col , n , m) ;


        return total ;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<bool>>vis(m , vector<bool> (n , 0)) ;
        int maxArea = 0 ; 

        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (!vis[i][j] && grid[i][j] == 1)  maxArea = max(maxArea , dfs(grid , vis , i ,j , n , m)) ;
            }
        }

        return maxArea ;

    }
};