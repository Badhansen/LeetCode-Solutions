// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0, start = 0, end = height.size() - 1;
        while(start <= end){
            answer = max(answer, min(height[start], height[end]) * (end - start));
            if(height[start] > height[end]){
                end--;
            }
            else{
                start++;
            }
        }
        return answer;
    }
};

// Time Complexity: O(N), Where N is length of the array
// Space Complexity: O(1), It uses constant space