//@Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int answer = 0;
        
        int leftMax = 0, rightMax = 0;
        while(start < end){
            if(height[start] < height[end]){
                if(height[start] >= leftMax){
                    leftMax = height[start];
                }
                else{
                    answer += leftMax - height[start];
                }
                start++;
            }
            else{
                if(height[end] >= rightMax){
                    rightMax = height[end];
                }
                else{
                    answer += rightMax - height[end];
                }
                end--;
            }
        }
        
        return answer;
    }
};

// Time Complexity: O(N), where N is the length of the array
// Space Complexity: O(1), Here we use constant space
