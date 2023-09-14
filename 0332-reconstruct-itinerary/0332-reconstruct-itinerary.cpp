const int kMax = 305;

class Solution {
private:
    map<string, int> in, out;
    map<string, vector<string>> graph;
    vector<string> path;
    int index = 0, edges = 0;
public:
    void setUp(vector<vector<string>>& tickets) {
        in.clear(), out.clear();
        graph.clear();
        edges = tickets.size();
        for (auto t : tickets) {
            string from = t[0], to = t[1];
            graph[from].push_back(to);
            in[to]++, out[from]++;
        }
        for (auto &p : graph) {
            sort(p.second.rbegin(), p.second.rend());
        }
    }
    void dfs(string at) {
        while (out[at]) {
            string next = graph[at][--out[at]];
            dfs(next);
        }
        path.push_back(at);
    }
    vector<string> getEulerianPath(vector<vector<string>>& tickets) {
        setUp(tickets);
        dfs("JFK");
        if (path.size() != edges + 1) return {};
        reverse(path.begin(), path.end());
        return path;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> path = getEulerianPath(tickets);
        return path;
    }
};