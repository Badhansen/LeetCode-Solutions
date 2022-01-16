// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int maxDistToClosest(vector<int>& seat) {
        int lastSeen = 0, answer = INT_MIN;
        int length = seat.size();
        
        for(int i=0; i < length; i++){ 
            if(seat[i]){  
                lastSeen = 0;
            }
            else{
                lastSeen++;
                answer = max(answer, (lastSeen + 1) / 2);
            }
        }
        
        for(int i = 0; i < length; i++){
            if(seat[i]){
                answer = max(answer, i);
                break;
            }
        }
        
        for(int i = length - 1; i >= 0; i--){
            if(seat[i]){
                answer = max(answer, length - 1 - i);
                break;
            }
        }
        
        return answer;
    }
};

// Time Complexity: O(N), where N is the length of the array
// Space Complexity: O(1), Here we use constant space