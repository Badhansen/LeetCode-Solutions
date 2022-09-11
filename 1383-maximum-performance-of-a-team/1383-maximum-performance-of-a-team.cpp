class Node{
public:
    int speed, efficiency;
    Node(int s, int e){
        speed = s;
        efficiency = e;
    }
    bool operator < (const Node& a){
        if(efficiency == a.efficiency){
            return speed > a.speed;
        }
        return efficiency > a.efficiency;
    }
};
class Solution {
    const int MOD = 1000000007;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Node> vt;
        for(int i = 0; i < n; i++){
            vt.push_back(Node(speed[i], efficiency[i]));
        }
        sort(vt.begin(), vt.end());
        priority_queue<int> qt;
        long long sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            qt.push(-vt[i].speed);
            sum += vt[i].speed;
            if(qt.size() > k){
                sum += qt.top();
                qt.pop();
            }  
            ans = max(ans, sum * vt[i].efficiency);
        }
        return ans % MOD;
    }
};