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
    int findPeakElement(MountainArray &nums) {
        int low = 0;
        int high = nums.length() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums.get(mid) > nums.get(mid + 1)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int search(MountainArray &nums, int target, int low, int high, int flag) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums.get(mid) == target) {
                return mid;
            } else if (nums.get(mid) < target) {
                if (flag) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (flag) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return 1e9;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int pick = findPeakElement(mountainArr);
        //cout << pick << endl;
        int left = search(mountainArr, target, 0, pick, 1);
        int right = search(mountainArr, target, pick + 1, n - 1, 0);
        //cout << left << " " << right << endl;
        if (left == 1e9 && right == 1e9) {
            return -1;
        } else {
            return min(left, right);
        }
    }
};