class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size() ;
        int m = matrix[0].size() ;

        priority_queue<int , vector<int> , greater<int>>pq ;

        for (int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j ++){
                pq.push(matrix[i][j]) ;
            }
        }

        int start = 0 ;

        while (!pq.empty() && k > 0){
            start = pq.top() ;
            pq.pop() ;
            k -- ;
        }

        return start ;
        
    }
};