class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> curr;

        if (matrix[0][0] > target) return false;

        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] > target) {
                curr = matrix[i - 1];
                break;
            } else if (matrix[i][0] == target)
                return true;
        }
        if (matrix.back()[0] <= target) {
            curr = matrix.back();
        }

        int i = 0, j = curr.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (curr[mid] == target)
                return true;
            else if (curr[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return false;
    }
};
