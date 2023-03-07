class Solution {
public:
    bool isTripsValid(vector<int>& time, long long t, long long totalTrips) {
        long long candone = 0;
        for (int i = 0; i < time.size(); i++) {
            if (candone >= totalTrips) {
                return true;
            }
            candone += (t / time[i]);
        }
        return candone >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0, high = 1e18, ans = 0;
        while (low <= high) {
            long long mid = (high - low) / 2 + low;
            bool isValid = isTripsValid(time, mid, totalTrips);
            if (isValid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};