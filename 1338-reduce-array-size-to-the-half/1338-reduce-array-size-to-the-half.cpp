class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        priority_queue<int> qt;
        for(auto &el : arr){
            count[el]++;
        }
        for(auto &el : count){
            qt.push(el.second);
        }
        int n = arr.size(), sum = 0, cnt = 0;
        n /= 2;
        while(!qt.empty()){
            sum += qt.top();
            cnt++;
            if(sum >= n) break;
            qt.pop();
        }
        return cnt;
    }
};