// Programming Language Used: C++

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int, int>> work;
        multiset<int> workers;
        int jobLen = difficulty.size();
        int workerLen = worker.size();
        int answer = 0;
        
        for(int i = 0; i < jobLen; i++){
            work.push({profit[i], difficulty[i]});    
        }
        
        for(int i = 0; i < workerLen; i++){
            workers.insert(worker[i]);
        }
        
        while(workers.size() && !work.empty()){
            pair<int, int> wTop = work.top();
            auto pos = workers.upper_bound(wTop.second);
            
            if(pos == workers.end()){
                pos--;
                if(*pos >= wTop.second){
                    answer += wTop.first;
                    workers.erase(pos);
                }
                else
                    work.pop();
            }
            else{
                answer += wTop.first;
                workers.erase(pos);
            }
        }
        
        return answer;
    }
};

// Time Complexity: O(NlogN + PlogP), here N = number of jobs and P = number of people
// Space Complexity: O(N + P)