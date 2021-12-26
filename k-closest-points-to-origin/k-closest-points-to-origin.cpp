#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
struct Node{
    int x, y, distance;
    Node(){}
    Node(int a, int b, int d){
        x = a, y = b, distance = d;
    }
    bool operator < (const Node& p) const {
        if(distance == p.distance){
            return x >= p.x;
        }
        return distance < p.distance; 
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Node> qt;
        for(auto el : points){
            int a = el[0], b = el[1];
            int distance = a * a + b * b;
            Node p(a, b, distance);
            qt.push(p);
            if(qt.size() > k) qt.pop();
        }
        vector<vector<int>> answer;
        while(!qt.empty()){
            Node p = qt.top();
            qt.pop();
            answer.push_back({p.x, p.y});
        }
        return answer;
    }
};