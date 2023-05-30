class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        map<char, int> memory;
        memory['M'] = 1000;
        memory['D'] = 500;
        memory['C'] = 100;
        memory['L'] = 50;
        memory['X'] = 10;
        memory['V'] = 5;
        memory['I'] = 1;
        for(int i = 0; i < s.size() - 1; i++){
            if(memory[s[i]] < memory[s[i + 1]]){
                number = number - memory[s[i]];
            }
            else{
                number += memory[s[i]];
            }
        }
        number += memory[s[s.size() - 1]];
        return number;
    }
};