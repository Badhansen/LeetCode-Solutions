class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> indices(plantTime.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j){
            return growTime[i] > growTime[j];
        });
        int answer = 0, currPlantTime = 0;
        for (int i : indices) {
            currPlantTime += plantTime[i];
            answer = max(answer, currPlantTime + growTime[i]);
        }
        return answer;
    }
};