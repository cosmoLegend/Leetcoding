class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int iMax=0,iMin=INT_MAX;
        int jMax=0,jMin=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                     iMax=max(iMax,i);
                     jMax=max(jMax,j);
                     iMin=min(iMin,i);
                     jMin=min(jMin,j);
                }
            }
        }
        return (iMax-iMin+1)*(jMax-jMin+1);
        
    }
};