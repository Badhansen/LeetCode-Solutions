// 1 last try

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int target = threshold * k;
        int sum = 0, answer = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (i < k - 1) continue;
            if (i > k - 1) sum -= arr[i - k];
            if (sum >= target) answer++;
        }
        return answer;
    }
};

// Time: O(N), N = Length of the array
// Space: O(1)