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