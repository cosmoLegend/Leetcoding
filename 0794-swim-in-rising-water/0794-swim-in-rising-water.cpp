class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size() ;

        vector<vector<bool>>vis(n , vector<bool> (n , false)) ;

        priority_queue<vector<int> , vector<vector<int>> , greater<>>pq ;
        int maxTime = 0 ; 

        pq.push({grid[0][0] , 0  , 0}) ;
        vis[0][0] = 1 ;

        while (!pq.empty()){
            int maxDepth = pq.top()[0] ;
            int row = pq.top()[1] ;
            int col = pq.top()[2] ; 

            if(row == n - 1 && col == n - 1) return maxDepth ; 

            pq.pop() ;
            vector<int> delrc = {1 , 0 , -1 , 0 , 1} ;


            for (int i = 0 ; i < delrc.size() - 1 ; i++){
                int nr = row + delrc[i] ;
                int nc = col + delrc[i + 1] ;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == 0){
                    pq.push({max(grid[nr][nc] , maxDepth) , nr , nc}) ;
                    vis[nr][nc] = 1 ;
                }
            }

            maxTime = max (maxDepth , maxTime) ; 

        }


        return -1 ; 
        
    }
};