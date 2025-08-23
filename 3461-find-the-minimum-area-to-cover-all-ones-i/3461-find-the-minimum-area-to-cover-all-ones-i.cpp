class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int n = grid.size() ;
        int m = grid[0].size() ;
        int minX = INT_MAX , maxX = INT_MIN , minY = INT_MAX , maxY = INT_MIN ;

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (grid[i][j] == 1){
                minX = min(minX , i) ;
                minY = min(minY , j) ;
                maxY = max(maxY , j) ;
                maxX = max(maxX , i) ;
                }
            }
        }

        return (maxX - minX + 1) * (maxY - minY + 1) ;
        
    }
};