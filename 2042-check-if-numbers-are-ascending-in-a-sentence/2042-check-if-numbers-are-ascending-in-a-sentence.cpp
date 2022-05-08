class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1, next;
        string word;
        stringstream ss;
        ss << s;
        while(ss >> word){
            if(isdigit(word[0])){
                next = stoi(word);
                if(next <= prev){
                    return false;
                }
                else{
                    prev = next;
                }
            }
        }
        return true;
    }
};