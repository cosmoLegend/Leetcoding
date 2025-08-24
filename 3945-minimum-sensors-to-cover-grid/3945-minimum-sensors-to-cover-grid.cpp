class Solution {
public:
    int minSensors(int n, int m, int k) {

        double total = 0 ;

        total = ceil((double)n / (2*k + 1)) * ceil ((double)m / (2*k + 1)) ;

        return static_cast<int>(total) ;
        
    }
};