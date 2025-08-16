class Solution {
public:
    void dfs (vector<vector<int>> &vis , int i , vector<vector<int>> & grid){

    }

    int orangesRotting(vector<vector<int>>& grid) {

        int minTime = 0 ; 
        int m = grid.size() ;
        int n = grid[0]. size() ;

        int freshCount = 0 ;


        vector<vector<int>>vis(m  , vector<int> (n  , 0)) ;

        queue<pair<pair<int,int>,int>>q ;



        for (int i = 0 ; i < m ; i ++){
            for (int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2)  {
                    q.push({{i , j} , 0}) ;
                    vis[i][j] = 2 ;
                }
                if (grid[i][j] == 1) freshCount ++ ;
            }
        }

        int delrow[] = {1 , 0 , - 1 , 0} ;
        int delcol[] = {0 , 1 , 0 , -1} ;

        //int count = 0 ;

        while (!q.empty()) {
            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int time = q.front().second ;
            minTime = time ;
            q.pop() ;

            for (int dir = 0 ; dir < 4 ; dir ++){
                int nrow = row + delrow[dir] ;
                int ncol = col + delcol[dir] ;

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    vis[nrow][ncol] = 2 ;
                    q.push({{nrow , ncol} , time + 1}) ;
                    freshCount -- ;
                }
            }
        }

        if (freshCount) return -1 ;     

        return minTime ; 
    }
};