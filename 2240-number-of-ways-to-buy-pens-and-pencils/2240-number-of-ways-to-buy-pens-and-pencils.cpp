class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int pen = total / cost1;
        long long answer = 0;
        for(int i = 0; i <= pen; i++){
            answer += (total - cost1 * i) / cost2;
            answer++;
        }
        return answer;
    }
};