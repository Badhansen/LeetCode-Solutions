//@Author: KING-SEN

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses + 1];
        vector<int> indeg(numCourses + 1, 0);
        for(auto &el : prerequisites){
            indeg[el[0]]++;
            graph[el[1]].push_back(el[0]);
        }
        vector<bool> visited(numCourses + 1, false);
        vector<int> course;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) course.push_back(i);
        }
        
        int done = 0,id = 0;
        while(id < course.size()){
            done++;
           
            int curr = course[id];
            for(auto &v: graph[curr]){
                if(indeg[v] > 0){
                    indeg[v]--;
                    if(indeg[v] == 0) course.push_back(v);
                }
            }
            id++;
        }
        return done == numCourses;
    }
};
/*
class Solution {
private:
    vector<vector<int>> graph;
    set<int> visited, path;
public:
    bool dfs(int src) {
        if (path.count(src)) {
            return true;
        }
        visited.insert(src);
        path.insert(src);
        bool result = false;
        for (auto dest : graph[src]) {
            if (!visited.count(dest)) {
                result |= dfs(dest);
            }
            if (path.count(dest)) {
                return true;
            }
        }
        path.erase(src);
        return result;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        graph.resize(n + 1);
        for (auto &e : pre){
            graph[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++) {
            if (dfs(i)) {
                return false;
            }
        }
        return true;
    }
};
*/