class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lastIndex = m + n - 1;
        while(m > 0 && n > 0){
            if(nums1[m - 1] > nums2[n - 1]){
                nums1[lastIndex] = nums1[m - 1];
                m--;
                lastIndex--;
            }
            else{
                nums1[lastIndex] = nums2[n - 1];
                n--;
                lastIndex--;
            }
        }
        while(n > 0){
            nums1[lastIndex] = nums2[n - 1];
            n--;
            lastIndex--;
        }
    }
};