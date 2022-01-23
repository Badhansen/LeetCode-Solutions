class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> qt;
        for(int i = 1; i <= 9; i++){
            qt.push(i);
        }
        while(!qt.empty()){
            int num = qt.front();
            qt.pop();
            if(num >= low && num <= high){
                ans.push_back(num);
            }
            if(num > high) break;
            int rem = num % 10;
            if(rem < 9){
                qt.push(num * 10 + (rem + 1));
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};