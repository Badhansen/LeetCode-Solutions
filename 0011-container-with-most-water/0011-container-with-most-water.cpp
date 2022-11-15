// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int answer = 0;
        while (left <= right) {
            int area = min(height[left], height[right]) * (right - left);
            answer = max(answer, area);
            if (height[left] > height[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return answer;
    }
};

// Time Complexity: O(N), Where N is length of the array
// Space Complexity: O(1), It uses constant space