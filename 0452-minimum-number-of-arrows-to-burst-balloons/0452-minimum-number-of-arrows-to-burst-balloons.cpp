class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int minArrows = 1 ;
        int n = points.size() ;
        sort (points.begin() , points.end()) ;
        int start = points[0][1] ;

        for (int i = 1 ; i < n ; i++){
            if (start < points[i][0]) minArrows ++ , start = points[i][1] ;
            else start = min (points[i][1] , start) ;
        }


        return minArrows ;
    }
};