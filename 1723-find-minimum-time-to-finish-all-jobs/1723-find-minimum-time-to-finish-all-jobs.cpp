class Solution {
public:
    bool dfs(int pos, int target, vector<int>& jobs, vector<int>& worker){
        if(pos == jobs.size()){
            return true;
        }
        for(int i = 0; i < worker.size(); i++){
            if(worker[i] + jobs[pos] <= target){
                worker[i] += jobs[pos];
                if(dfs(pos + 1, target, jobs, worker)){
                    return true;
                }
                worker[i] -= jobs[pos];
            }
            if(worker[i] == 0){
                break;
            }
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int len = jobs.size();
        int answer, low, high;
        sort(jobs.begin(), jobs.end(), greater<int>());
        low = answer = jobs[0];
        high = accumulate(jobs.begin(), jobs.end(), 0);
        while(low <= high){
            int mid = (low + high) / 2;
            vector<int> worker(k);
            if(dfs(0, mid, jobs, worker)){
                answer = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return answer;
    }
};