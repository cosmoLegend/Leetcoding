class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int firstodd = n * n ;
        int firsteven = n * (n + 1) ;

        return gcd (firsteven , firstodd) ;
    }
};