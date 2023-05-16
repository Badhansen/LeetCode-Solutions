// @Author: KING-SEN

class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        int len = peaks.size();
        for (int i = 0; i < len; i++) {
            int x = peaks[i][0], y = peaks[i][1];
            peaks[i][0] = x - y;
            peaks[i][1] = x + y;
        }
        sort(peaks.begin(), peaks.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int invisible_count = 0, end = 0;
        for (int i = 0; i < len - 1;) {
            end = peaks[i][1];
            int j = i + 1;
            if (peaks[i][0] == peaks[j][0] && peaks[i][1] == peaks[j][1]) {
                invisible_count++;
            }
            while (j < len) {
                int y = peaks[j][1];
                if (y > end) {
                    break;
                }
                invisible_count++;
                j++;
            }
            i = j;
        }
        return len - invisible_count;
    }
};