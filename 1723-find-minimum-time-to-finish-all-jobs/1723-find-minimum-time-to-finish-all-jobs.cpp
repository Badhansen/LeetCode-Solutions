class Solution {
private:
    int result, len, k;
public:
    void dfs(int pos, vector<int>& jobs, vector<int>& count){
        if(pos == len){
            result = min(result, *max_element(count.begin(), count.end()));
            return;
        }
        for(int i = 0; i < k; i++){
            if(count[i] + jobs[pos] < result){
                count[i] += jobs[pos];
                dfs(pos + 1, jobs, count);
                count[i] -= jobs[pos];
            }
            if(count[i] == 0){
                break;
            }
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        len = jobs.size(), this->k = k;
        sort(jobs.begin(), jobs.end(), greater<int>());
        result = accumulate(jobs.begin(), jobs.end(), 0);
        vector<int> count(k, 0);
        dfs(0, jobs, count);
        return result;
    }
};