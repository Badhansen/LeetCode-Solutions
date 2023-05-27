//@Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        
        int maxleft = height[start];
        int maxright = height[end];
        
        int answer = 0;
        
        while (start < end) {
            if (maxleft <= maxright) {
                start++;
                maxleft = max(maxleft, height[start]);
                answer += maxleft - height[start];
            } else {
                end--;
                maxright = max(maxright, height[end]);
                answer += maxright - height[end];
            }
        }
            
        return answer;
    }
};

// Time Complexity: O(N), where N is the length of the array
// Space Complexity: O(1), Here we use constant space
