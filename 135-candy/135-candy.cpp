class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size(), answer = 0;
        vector<pair<int, int>> order;
        vector<int> candy(len, 1);
        for(int i = 0; i < len; i++){
            order.push_back({ratings[i], i});
        }
        sort(order.begin(), order.end());
        for(int i = 0; i < len; i++){
            int rating = order[i].first, id = order[i].second;
            int c = candy[id];
            if(id - 1 >= 0 && ratings[id - 1] < ratings[id]){
                c = max(c, candy[id - 1] + 1);
            }
            if(id + 1 < len && ratings[id + 1] < ratings[id]){
                c = max(c, candy[id + 1] + 1);
            }
            candy[id] = c;
        }
        for(int i = 0; i < len; i++){
            answer += candy[i];
        }
        return answer;
    }
};