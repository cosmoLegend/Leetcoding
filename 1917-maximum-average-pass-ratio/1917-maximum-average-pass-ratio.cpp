class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size() ;
        priority_queue<pair<double , int>>pq ;

        for (int i = 0 ; i < n ; i++){
            pq.push({(double)(classes[i][0] + 1) / (classes[i][1] + 1) - (double)classes[i][0]/ classes[i][1] , i}) ;
        }

        for (int i = 0 ; i < extraStudents ; i++){
            double gain = pq.top().first ;
            int idx = pq.top().second ;
            pq.pop() ;
            classes[idx][0] ++ ;
            classes[idx][1] ++ ;
            pq.push({(double)(classes[idx][0] + 1) / (classes[idx][1] + 1) - (double)classes[idx][0]/ classes[idx][1], idx}) ;

            
        }

        double sum = 0 ;

        for (auto &c : classes){
            sum += 1.0 * c[0] / c[1] ;
        }


        return sum / n ; 

    }
};