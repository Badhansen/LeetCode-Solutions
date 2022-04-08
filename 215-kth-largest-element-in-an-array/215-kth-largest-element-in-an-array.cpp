class Solution {
public:
    int partition(vector<int>& a, int left, int right, int pIndex){
        // pick `pIndex` as a pivot from the array
        int pivot = a[pIndex];

        // Move pivot to end
        swap(a[pIndex], a[right]);

        // elements less than the pivot will be pushed to the left of `pIndex`;
        // elements more than the pivot will be pushed to the right of `pIndex`;
        // equal elements can go either way
        pIndex = left;

        // each time we find an element less than or equal to the pivot, `pIndex`
        // is incremented, and that element would be placed before the pivot.
        for (int i = left; i < right; i++)
        {
            if (a[i] >= pivot)
            {
                swap(a[i], a[pIndex]);
                pIndex++;
            }
        }

        // move pivot to its final place
        swap(a[pIndex], a[right]);

        // return `pIndex` (index of the pivot element)
        return pIndex;
    }
    int quickselect(vector<int>& nums, int left, int right, int k){
        while(1){
            // If the array contains only one element, return that element
            if (left == right) {
                return nums[left];
            }

            // select `pIndex` between left and right
            int pivot = left + rand() % (right - left + 1);

            pivot = partition(nums, left, right, pivot);

            // The pivot is in its final sorted position
            if (k == pivot) {
                return nums[k];
            }

            // if `k` is less than the pivot index
            else if (k < pivot) {
                right = pivot - 1;
            }

            // if `k` is more than the pivot index
            else {
                left = pivot + 1;
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size() - 1, k - 1);
    }
};