class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Len = nums1.size(), nums2Len = nums2.size();
        if(nums1Len > nums2Len){
            return findMedianSortedArrays(nums2, nums1);
        }
        int start = 0, end = nums1Len;
        while(start <= end){
            int partX = (start + end) / 2;
            int partY = (nums1Len + nums2Len + 1) / 2 - partX;
            int maxLeftX, minRightX, maxLeftY, minRightY;
            maxLeftX = (partX == 0) ? INT_MIN : nums1[partX - 1];
            minRightX = (partX == nums1Len) ? INT_MAX : nums1[partX];
            maxLeftY = (partY == 0) ? INT_MIN : nums2[partY - 1];
            minRightY = (partY == nums2Len) ? INT_MAX : nums2[partY];
            
            // x1 x2 x3 x4 x5
            // y1 y2 y3 y4 y5 y6     
            // x1 x2      | x3 x4 x5 
            // y1 y2 y3 y4| y5 y6
            
// left max | right min x => initialize with -inf or before the bar element | +inf or after the bar element
// left max | right min y => initialize with -inf or before the bar element | +inf or after the bar element
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                if((nums1Len + nums2Len) & 1){
                    return (double) max(maxLeftX, maxLeftY);
                }
                else{
                    return (double) (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                }
            }
            else if(maxLeftX > minRightY){
                end = partX - 1;
            }
            else{
                start = partX + 1;
            }
        }
        return -1;
    }
};