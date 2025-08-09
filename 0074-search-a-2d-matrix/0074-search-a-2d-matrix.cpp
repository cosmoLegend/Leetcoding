class Solution {
public:
    bool BScol(vector<vector<int>>& matrix, int target, int row, int m) {
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n - 1;
        int row = -1;

        // Binary search to find the correct row
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][m - 1]) {
                row = mid;
                break;
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (row == -1) return false; // no valid row found
        return BScol(matrix, target, row, m);
    }
};
