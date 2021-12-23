// @author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        
        for(auto &courses : prerequisites){
            graph[courses[1]].push_back(courses[0]);
            inDegree[courses[0]]++;
        }
        
        queue<int> courseList;
        
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                courseList.push(i);
            }
        }
        
        vector<int> order;
        
        while(!courseList.empty()){
            int node = courseList.front();
            courseList.pop();
            
            order.push_back(node);
            
            for(auto &n : graph[node]){
                inDegree[n]--;
                if(inDegree[n] == 0){
                    courseList.push(n);
                }
            }
        }
        return numCourses == order.size() ? order : vector<int>();
    }
};

// Time Complexity: O(V + E), where V represents the number of vertices and E represents the number of edges
// Space complexity: O(V + E)