class Solution {
   public:
    bool binSer(vector<int> arr, int target) {
        int i = 0, j = arr.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (arr[mid] == target)
                return true;
            else if (arr[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix.size() - 1, row = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target) {
                row = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        if (row == -1) return false;
        return binSer(matrix[row], target);

        return false;
    }
};
