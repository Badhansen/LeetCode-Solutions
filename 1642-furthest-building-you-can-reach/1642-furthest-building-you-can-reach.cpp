// 1 last try

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> que;
        
        for(int i = 0; i < n - 1; i++){
            int neededBrick = heights[i + 1] - heights[i];
            
            if(neededBrick > 0) que.push(neededBrick);
            
            if(que.size() > ladders){
                bricks -= que.top();
                que.pop();
            }
            
            if(bricks < 0) return i;
        }
        
        return n - 1;
    }
};

// Time: O(N * log N), N = length of the array
// Space: O(N)