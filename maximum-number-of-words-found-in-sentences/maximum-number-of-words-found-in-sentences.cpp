class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int answer = 0;
        int spaceCount = 0;
        for(auto &line : sentences){
            spaceCount = 0;
            for(auto &c : line){
                if(c == ' ')
                    spaceCount++;
            }
            answer = max(answer, spaceCount);
        }
        return answer + 1;
    }
};