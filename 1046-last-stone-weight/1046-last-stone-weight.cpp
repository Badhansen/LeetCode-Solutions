class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> que;
        int size = stones.size();
        if(size == 1){
            return stones[0];
        }
        for(int i = 0; i < size; i++){
            que.push(stones[i]);
        }
        while(que.size() > 1){
            int x = que.top();
            que.pop();
            int  y = que.top();
            que.pop();
            int t = abs(x - y);
            if(t != 0)
                que.push(t);
        }
        if(que.size()){
            return que.top();
        }
        return 0;
    }
};