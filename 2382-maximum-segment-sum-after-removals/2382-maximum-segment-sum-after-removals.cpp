class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<long long> ans;
        vector<long long> sum(n + 1, 0);
        set<pair<int, int>> segments;
        multiset<long long, greater<long long>> segments_max;
        for (int i = 1; i <= n; i++) {
            sum[i] += sum[i - 1] + nums[i - 1];
        }
        segments.insert({0, n - 1});
        segments_max.insert(sum[n]);
        for (auto q : removeQueries) {
            auto it = segments.lower_bound({q, 100000});
            it = prev(it);
            int l = it->first, r = it->second;
            segments.erase(it);
            long long curr_sum = sum[r + 1] - sum[l];
            segments_max.erase(segments_max.find(curr_sum));
            
            if (l <= q - 1) {
                curr_sum = sum[q] - sum[l];
                segments_max.insert(curr_sum);
                segments.insert({l, q - 1});
            }
            if (q + 1 <= r) {
                curr_sum = sum[r + 1] - sum[q + 1];
                segments_max.insert(curr_sum);
                segments.insert({q + 1, r});
            }
            ans.push_back(*segments_max.begin());
        }
        return ans;
    }
};