class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr = arr[0], win = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > curr) {
                curr = arr[i];
                win = 0;
            }
            win++;
            if (win == k) {
                return curr;
            }
        }
        return curr;
    }
};