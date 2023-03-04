// Sparse Table from CP-Algorithm
const int MAXN = 1e5;
const int K = 25;

class Solution {
private:
    int lg[MAXN+1];
    int st_min[MAXN][K + 1];
    int st_max[MAXN][K + 1];
public:
    void solve(vector<int> &nums) {
        int N = nums.size();
        lg[1] = 0;
        for (int i = 2; i <= MAXN; i++) {
            lg[i] = lg[i/2] + 1;
        }
        
        for (int i = 0; i < N; i++) {
            st_min[i][0] = nums[i];
            st_max[i][0] = nums[i];
        }

        for (int j = 1; j <= K; j++) {
            for (int i = 0; i + (1 << j) <= N; i++) {
                st_min[i][j] = min(st_min[i][j-1], st_min[i + (1 << (j - 1))][j - 1]);
                st_max[i][j] = max(st_max[i][j-1], st_max[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    pair<int, int> get(int L, int R){
        int j = lg[R - L + 1];
        int minimum = min(st_min[L][j], st_min[R - (1 << j) + 1][j]);
        int maximum = max(st_max[L][j], st_max[R - (1 << j) + 1][j]);
        return {minimum, maximum};
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        solve(nums);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int start = -1, end = -1;
            int low = i, high = n - 1;
            // for upper bound
            while (low <= high) {
                int mid = (low + high) / 2;
                pair<int, int> res = get(i, mid);
                if (res.first == minK && res.second == maxK) {
                    end = mid;
                    low = mid + 1;
                } else {
                    if (res.first < minK || res.second > maxK) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            if (end == -1) continue;
            // for lower bound
            low = i, high = n - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                pair<int, int> res = get(i, mid);
                if (res.first == minK && res.second == maxK) {
                    start = mid;
                    high = mid - 1;
                } else {
                    if (res.first < minK || res.second > maxK) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            if (start == -1) continue;
            ans += end - start + 1;
        }
        return ans;
    }
};