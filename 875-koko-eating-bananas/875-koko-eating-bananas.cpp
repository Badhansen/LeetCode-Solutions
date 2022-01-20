class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = 1e9, answer = 0;
        while(start <= end){
            int mid = (end - start) / 2 + start;
            int totalHour = 0;
            for(auto &p : piles){
                totalHour += p / mid + (p % mid != 0);
            }
            if(totalHour <= h){
                answer = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return answer;
    }
};