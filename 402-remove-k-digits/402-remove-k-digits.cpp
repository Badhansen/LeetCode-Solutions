class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for(auto digit : num){
            while(result.size() && k && result.back() > digit){
                result.pop_back();
                k--;
            }
            if(digit == '0'){
                if(result.size()){
                    result.push_back(digit);
                }
            }
            else{ 
                result.push_back(digit);
            }
        }
        while(k && result.size()){
            k--;
            result.pop_back();
        }
        return result.size() == 0 ? "0" : result;
    }
};

// Time: O(N), N = Length of the String
// Space: O(N)
/*
class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();
        stack<int> digits;
        string ans;
        for(int curr = 0; curr < len; curr++){
            while(digits.size() && k && num[digits.top()] > num[curr]){
                k--;
                digits.pop();
            }
            digits.push(curr);
        }
        while(k && !digits.empty()){
            k--;
            digits.pop();
        }
        while(!digits.empty()){
            ans.push_back(num[digits.top()]);
            digits.pop();
        }
        while(ans.size() && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans.size() == 0 ? "0" : ans;
    }
};

// Time: O(N), N = Length of the String
// Space: O(N)
*/