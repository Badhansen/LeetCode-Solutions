class Solution {
private:
    set<vector<int>> result;
public:
    void solve(int pos, int n, vector<int>& nums, vector<int> path) {
        result.insert(path);
        for (int i = pos; i < n; i++) {
            path.push_back(nums[i]);
            solve(i + 1, n, nums, path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums.size(), nums, {});
        vector<vector<int>> answer;
        for (auto &r : result) {
            answer.push_back(r);
        }
        return answer;
        /*
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        unordered_map<string, bool> isExist;
        int length = nums.size();
        for(int i = 0; i < (1 << length); i++){
            vector<int> ans;
            string str = "";
            for(int j = 0; j < length; j++){
                if(i & (1 << j)){
                    ans.push_back(nums[j]);
                    str += to_string(nums[j]);
                }
            }
            if(isExist.find(str) == isExist.end()){
                answer.push_back(ans);
                isExist[str] = true;
            }
        }
        return answer;
        */
    }
};