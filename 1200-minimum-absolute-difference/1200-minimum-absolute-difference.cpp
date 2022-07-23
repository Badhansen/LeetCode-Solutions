// Sort + 2 Traversal
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;
        int diff, minDiff = INT_MAX; 
        for(int i = 1; i < arr.size(); i++){
            diff = arr[i] - arr[i - 1];
            minDiff = min(minDiff, diff);
        }
        for(int i = 1; i < arr.size(); i++){
            diff = arr[i] - arr[i - 1];
            if(diff == minDiff){
                answer.push_back({arr[i - 1], arr[i]});
            }
        }
        return answer;
    }
};