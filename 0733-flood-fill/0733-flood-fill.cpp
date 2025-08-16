class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size() ;
        int n = image[0].size() ;

        vector<vector<int>>vis(m , vector<int>(n , 0)) ;

        // for (int i = 0 ; i < m ; i++){
        //     for (int j = 0 ; j < n ; j++){
        //         if(grid[i][j] == 1)
        //     }
        // }
        int oldColor = image[sr][sc] ;
        queue<pair<int , int>> q ;
        if (image[sr][sc] == color) return image ;
        q.push({sr , sc}) ;
        vis[sr][sc] = 1 ;
        image[sr][sc] = color ;
        

        int delrow[] = {-1 , 0 , 1 , 0} ;
        int delcol[] = {0 , 1 , 0 , -1 } ;


        while(!q.empty()){
            int row = q.front().first ;
            int col = q.front().second ;
            q.pop() ;
            for (int dir = 0 ; dir < 4 ; dir ++){
                int nrow = row + delrow[dir] ;
                int ncol = col + delcol[dir] ;
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] != 1 && image[nrow][ncol] == oldColor) {
                    vis[nrow][ncol] = 1 ;
                    q.push({nrow , ncol}) ;
                    image[nrow][ncol] = color ;
                }
            }
            
        }

        return image ; 
        
    }
};