// @Author: KING-SEN

class Solution {
public:
    int LengthOfLDS(const vector<int> &nums) {
        vector<int> seq;
        for (int i = 0; i < nums.size(); i++) {
            if (seq.empty() or seq.back() <= nums[i]) {
                seq.push_back(nums[i]);
            } else {
                int position = upper_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[position] = nums[i];
            }
        }
        return seq.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int answer = 0;
        for (int i = 0; i < k; i++) {
            vector<int> nums;
            for (int j = i; j < arr.size(); j += k) {
                nums.push_back(arr[j]);
            }
            answer += (nums.size() - LengthOfLDS(nums));
        }
        return answer;
    }
};

/*

Time: O(K * N/K * log(N/K)) = O(N * log(N/K)), where N <= 10^5 is length of arr, K <= N.
We have total K new arr, each array have up to N/K elements.
We need O(M * logM) to find the longest non-decreasing subsequence of an array length M.

Space: O(N / K)

*/