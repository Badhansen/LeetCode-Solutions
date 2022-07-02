// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size();
        deque<int> seen;
        vector<int> answer;
        
        for(int i = 0; i < length; i++){
            if(!seen.empty() && seen.front() == i - k){
                seen.pop_front();
            }
            
            while(!seen.empty() && nums[seen.back()] <= nums[i]){
                seen.pop_back();
            }
            
            seen.push_back(i);
            
            if(i >= k - 1){
                answer.push_back(nums[seen.front()]);
            }
        }
        
        return answer;
    }
};

// Time Complexity: O(N), here N = Length of the array, we are using deque and since each element is processed 
// exactly twice - it's index added and then removed from the deque.
// So overall time complexity will be N

// Space Complexity: O(K), here K = Length of the window. At any times there will be K elements in the deque. So Space complexity will be O(K).