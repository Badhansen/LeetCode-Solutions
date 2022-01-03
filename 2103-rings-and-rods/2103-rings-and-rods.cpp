class Solution {
public:
    int countPoints(string rings) {
        int len = rings.size();
        vector<vector<int>> count(10, vector<int>(3, 0));
        
        for(int i = 0; i < rings.size(); i += 2){
            if(rings[i] == 'R'){
                count[rings[i + 1] - '0'][0]++;
            }
            if(rings[i] == 'G'){
                 count[rings[i + 1] - '0'][1]++;
            }
            if(rings[i] == 'B'){
                 count[rings[i + 1] - '0'][2]++;
            }
        }
        
        int answer = 0;
        
        for(int i = 0; i < 10; i++){
            if(count[i][0] && count[i][1] && count[i][2])
                answer++;
        }
        
        return answer;
    }
};