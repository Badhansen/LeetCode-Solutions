class Solution {
public:
    int maximumSwap(int num) {
        stringstream ss;
        string str;
        
        ss << num;
        ss >> str;
        
        int answer = num;
        
        for(int i = 0; i < str.size(); i++){
            for(int j = str.size() - 1; j > i; j--){
                swap(str[i], str[j]);
                stringstream temp(str);
                int mNum;
                temp >> mNum;
                answer = max(answer, mNum);
                swap(str[i], str[j]);
            }
        }
        
        return answer;
    }
};