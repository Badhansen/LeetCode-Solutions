class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end) {
        int p = start, q = mid + 1, k = 0;
        vector<int> temp(end - start + 1);
        for (int i = start; i <= end; i++) {
            if (p > mid) {
                temp[k++] = nums[q++];
            } else if (q > end) {
                temp[k++] = nums[p++];
            } else if (nums[p] < nums[q]) {
                temp[k++] = nums[p++];
            } else {
                temp[k++] = nums[q++];
            }
        }
        for (int i = 0; i < k; i++) {
            nums[start++] = temp[i];
        }
    }
    void mergeSort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int mid = (end - start) / 2 + start;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};