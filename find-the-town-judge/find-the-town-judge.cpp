class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int arr[10001] = {0};
        for(auto const &x : trust){
            arr[x[0]]--;
            arr[x[1]]++;
        }
        for(int i = 1; i <= N; i++){
            if(arr[i] == N - 1) return i;
        }
        return -1;
    }
};