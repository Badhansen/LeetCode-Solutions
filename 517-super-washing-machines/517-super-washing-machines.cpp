class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size();
        int totalDress = accumulate(machines.begin(), machines.end(), 0);
        if(totalDress % len != 0){
            return -1;
        }
        int target = totalDress / len, csum = 0, ans = 0;
        for(int i = 0; i < len; i++){
            machines[i] = machines[i] - target;
            csum += machines[i];
            ans = max({ans, machines[i], abs(csum)});
        }
        return ans;
    }
};