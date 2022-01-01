// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lengthNum1 = nums1.size();
        int lengthNum2 = nums2.size();
        int totalSize = (lengthNum1 + lengthNum2);
        
        copy(nums2.begin(), nums2.end(), back_inserter(nums1));
        sort(nums1.begin(), nums1.end());
        
        double answer;
        
        if(totalSize & 1){
            answer = nums1[totalSize / 2];
            return answer;
        }
        else{
            answer = nums1[(totalSize / 2) - 1] + nums1[totalSize / 2];
            answer /= 2.0;
            return answer;
        }
    }
};

// Time Complexity: O(N log N), where N is the total size of nums1 ans nums2 array
// Space Complexity: O(N), to store the all array elements

