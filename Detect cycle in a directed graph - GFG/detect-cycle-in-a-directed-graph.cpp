//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

enum Colors {
    kWhite = 0,
    kGray,
    kBlack
};

int dfs(int src, vector<int>& visited, vector<int> graph[]) {
    visited[src] = Colors::kGray;
    for (auto dest : graph[src]) {
        if (visited[dest] == Colors::kGray) {
            return 1;
        }
        if (visited[dest] == Colors::kWhite && dfs(dest, visited, graph)) {
            return 1;
        }
    }
    visited[src] = kBlack;
    return 0;
}

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V + 1, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends