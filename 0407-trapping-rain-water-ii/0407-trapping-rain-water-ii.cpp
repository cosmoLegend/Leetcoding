class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size() ;
        int m = heightMap[0].size() ;

        if(n == 0) return 0 ;
        if(m == 0) return 0 ;
        if(n <= 1 || m <= 1) return 0 ; // as we need volume not the area 

        vector<vector<bool>> vis(n , vector<bool>(m , 0)) ;

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq ;

        // I will try pushing all the boundary cells

        for (int i = 0 ; i < n ; i++){
            pq.push({heightMap[i][0] , i , 0}) ;
            vis[i][0] = true ;
            pq.push({heightMap[i][m - 1] , i , m - 1}) ;
            vis[i][m - 1] = true ;
        }

        for (int j = 1 ; j < m - 1 ; j ++){
            pq.push({heightMap[0][j] , 0 , j});
            vis[0][j] = true ;
            pq.push({heightMap[n - 1][j] , n - 1 , j});
            vis[n - 1][j] = true ;
        }

        long long totalWater = 0 ;
        vector<int> delrow = {1 , 0 , -1 , 0} ;
        vector<int> delcol = {0 , 1 , 0 , -1} ;

        while (!pq.empty()){
            vector<int> cur = pq.top() ; //or auto cur = ..
            pq.pop() ; 
            int height = cur[0] ;
            int xc = cur[1] ;
            int yc = cur[2] ; 

            for (int i = 0 ; i < 4 ; i++){
                int nr = xc + delrow[i] ;
                int nc = yc + delcol[i] ;

                if(nc >= 0 && nc < m && nr >= 0 && nr < n && !vis[nr][nc]){
                    vis [nr][nc] = true ;
                    int nh = heightMap[nr][nc] ;
                    if(nh < height){
                        totalWater += height - nh ;
                        pq.push({height , nr , nc}) ;
                    }
                    else {
                        pq.push({nh , nr , nc}) ;
                    }
                }
            }
        }

        return totalWater ; 
        
    }
};