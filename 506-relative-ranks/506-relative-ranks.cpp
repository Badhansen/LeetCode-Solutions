class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> que;
        vector<string> ans(n);
        for(int i = 0; i < n; i++){
            que.push({score[i], i});
        }
        int count = 0;
        while(!que.empty()){
            int index = que.top().second;
    
            if(count == 0) ans[index] = "Gold Medal";
            else if(count == 1) ans[index] = "Silver Medal";
            else if(count == 2) ans[index] = "Bronze Medal";
            else ans[index] = to_string(count + 1);
            
            count++;
            que.pop();
        }
        
        return ans;
    }
};