class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int carry = 1;
        for(int i = n - 1; i >= 0; i--){
            int sum = carry + digits[i];
            if(sum > 9){
                carry = 1;
                ans.push_back(0);
            }
            else{
                carry = 0;
                ans.push_back(sum);
            }
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};