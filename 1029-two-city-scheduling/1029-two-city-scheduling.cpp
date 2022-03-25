struct Node{
    int a, b, distance;
    Node(int _a, int _b, int _d){
        a = _a;
        b = _b;
        distance = _d;
    }
    bool operator < (const Node &A) {
        if(distance == A.distance){
            if(a == A.a){
                return b > A.b;
            }
            return a < A.a;
        }
        return distance < A.distance;
    }
};
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<Node> pt;
        for(auto &x : costs){
            int a, b;
            a = x[0], b = x[1];
            pt.push_back(Node(a, b, a - b));
        }
        sort(pt.begin(), pt.end());
        int n = costs.size();
        int ans = 0;
        for(int i = 0; i < n / 2; i++){
            ans += pt[i].a;
        }
        for(int i = n / 2; i < n; i++){
            ans += pt[i].b;
        }
        return ans;
    }
};