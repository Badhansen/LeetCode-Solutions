class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        int n = courses.size();
        priority_queue<int> que;
        int time = 0;
        for(int c = 0; c < n; c++){
            time += courses[c][0];
            que.push(courses[c][0]);
            if(time > courses[c][1]){
                time -= que.top();
                que.pop();
            }
        }
        return (int)que.size();
    }
};