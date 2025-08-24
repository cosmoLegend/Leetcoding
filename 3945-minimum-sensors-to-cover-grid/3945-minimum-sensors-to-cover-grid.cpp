class Solution {
public:
    int minSensors(int n, int m, int k) {
        int s = 2 * k + 1;  // coverage side length

        int rows = (n + s - 1) / s;  // ceil(n/s)
        int cols = (m + s - 1) / s;  // ceil(m/s)

        return rows * cols;
    }
};
