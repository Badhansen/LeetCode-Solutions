class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) { 
        sort(people.begin(), people.end(), greater<int>());
        int fp = 0, bp = people.size() - 1, cnt = 0;
        while(fp <= bp){
            if(people[fp] + people[bp] <= limit){
                cnt++, fp++, bp--;
            }
            else{
                fp++, cnt++;
            }
        }
        return cnt;
    }
};