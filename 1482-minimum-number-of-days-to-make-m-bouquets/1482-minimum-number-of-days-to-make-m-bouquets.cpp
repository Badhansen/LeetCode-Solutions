class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int days, int m, int k) {
        int cnt = 0, items = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                cnt++;
                if (cnt == k) {
                    items++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return items >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = 1e9, answer = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(bloomDay, mid, m, k)) {
                high = mid - 1;
                answer = mid;
            } else {
                low = mid + 1;                
            }
        }
        return answer;
    }
};