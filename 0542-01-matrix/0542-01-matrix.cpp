class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size() ;
        int n = mat[0].size() ;

        //queue<pair<int , int>>q ;
        vector<vector<int>> vis (m , vector<int> (n , 0)) ;
        queue<pair<pair<int , int> , int>> q ;

        vector<vector<int>>distance(m , vector<int> ( n , 0)) ;

        for (int i = 0 ; i < m ; i ++){
            for (int j = 0 ; j < n ; j++){
                if (mat[i][j] == 0) {
                    q.push({{i , j} , 0}) ;
                    vis[i][j] = 1 ;
                }
            }
        }

        int delrow [] = {0 , 1 , -1 , 0} ;
        int delcol [] = {1 , 0 , 0 , -1} ;

        while (!q.empty()){
            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int dist = q.front().second ;
            q.pop() ;

            distance[row][col] = dist ;

            for (int dir = 0 ; dir < 4 ; dir ++){
                int nrow = row + delrow[dir] ;
                int ncol = col + delcol[dir] ;

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] != 1 ){
                    q.push({{nrow , ncol} , dist + 1}) ;
                    vis[nrow][ncol] = 1 ;
                }
            }

        }

        return distance ;
        
    }
};