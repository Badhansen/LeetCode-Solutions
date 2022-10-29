// @Author: KING-SEN

class Solution {
public:
    int numberOfCuts(vector<int>& sweetness, int value) {
        int sum = 0, cuts = 0;
        for (auto s : sweetness) {
            sum += s;
            if (sum >= value) {
                cuts++;
                sum = 0;
            }
        }
        return cuts;
    }
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int left = *min_element(sweetness.begin(), sweetness.end());
        int right = accumulate(sweetness.begin(), sweetness.end(), 0);
        int answer = 0;
        while (left <= right) {
            int mid = (left + right) >> 1;
            int cuts = numberOfCuts(sweetness, mid);
            if (cuts > k) {
                left = mid + 1;
                answer = mid;
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }
};