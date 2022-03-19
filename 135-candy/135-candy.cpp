class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> result(n, 1); // first rule
        set<pair<int,int>> Children;
        // n log(n)
        for(int i = 0; i < n; i++){
        Children.insert({ratings[i], i});
        }
        while(!Children.empty()){
            pair<int,int> u = *Children.begin();
            Children.erase(Children.begin());
            int left = u.second - 1, right = u.second + 1;
            int mx = 0;
            // rule 2 for left neighour
            if(left >= 0 && ratings[left] < ratings[u.second]){
              mx = max(mx, result[left] + 1);
            }
            // rule for right neighour 
            if(right < n && ratings[right] < ratings[u.second]){
              mx = max(mx, result[right] + 1);
            }
            result[u.second] = max(result[u.second], mx);
            }
            int answer = 0;
            for(int i = 0; i < n; i++){
            answer += result[i];
        }
        return answer;
    }
};