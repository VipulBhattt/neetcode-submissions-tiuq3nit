/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
   public:
    int binAsc(int target, MountainArray& mountainArr, int peak) {
        int i = 0, j = peak - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (mountainArr.get(mid) == target)
                return mid;
            else if (mountainArr.get(mid) > target) {
                j = mid - 1;
            } else
                i = mid + 1;
        }
        return -1;
    }
    int binDsc(int target, MountainArray& mountainArr, int peak) {
        int i = peak + 1, j = mountainArr.length() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (mountainArr.get(mid) == target)
                return mid;
            else if (mountainArr.get(mid) > target) {
                i = mid + 1;
            } else
                j = mid - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length(), i = 0, j = n - 1;
        int peak;

        while (i < j) {
            int mid = (i + j) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                i = mid + 1;
            else
                j = mid;
        }

        peak = i;
        if (mountainArr.get(peak) == target) return peak;
        if (binAsc(target, mountainArr, peak) != -1) return binAsc(target, mountainArr, peak);
        if (binDsc(target, mountainArr, peak) != -1) return binDsc(target, mountainArr, peak);
        return -1;
    }
};