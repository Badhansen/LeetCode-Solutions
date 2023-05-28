// @Author: KING-SEN

class Solution {
 private:
    unordered_map<int, int> seen_passenger;
 public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        for(auto p : passengers){
            seen_passenger[p] = 1;
        }
        int passenger_ID = 0, last_passenger, last_capacity = 0;
        for (int b = 0; b < buses.size(); b++) {
            last_capacity = 0;
            while(passenger_ID < passengers.size() && passengers[passenger_ID] <= buses[b] && last_capacity < capacity) {
                last_passenger = passengers[passenger_ID];
                last_capacity++;
                passenger_ID++;
            }
        }
        int answer;
        if (last_capacity < capacity) {
            answer = buses[buses.size() - 1];
        } else {
            answer = last_passenger - 1;
        }
        while (seen_passenger[answer] > 0) {
            answer--;
        }
        return answer;
    }
};
/*
[19,13,26,4,25,11,21]
[20,30,10]
[10,20,30]
  4 11 21
    12 25
    13 26
    19
  10
[4,11,13,19,21,25,26]
*/