class Node{
public:
    int value, position;
    Node(int v, int p){
        value = v;
        position = p;
    }
    bool operator < (const Node a){
        if(value == a.value){
            return position < a.position;
        }
        else{
            return value < a.value;
        }
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<array<int, 2>> vt;
        for(int i = 0; i < nums.size(); i++){
            vt.push_back({nums[i], i});
        }
        sort(vt.begin(), vt.end());
        for(int i = 1; i < nums.size(); i++){
            if(vt[i][0] == vt[i - 1][0] && vt[i][1] - vt[i - 1][1] <= k){
                return true;
            }
        }
        return false;
    }
};