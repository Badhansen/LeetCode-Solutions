class Solution {
public:
    string add(string a, string b){
        int carry = 0;
        int siz_a = a.size();
        int siz_b = b.size();
        string ans = "";
        for(int i = siz_a - 1; i >= 0; i--){
            if(a[i] == b[i] && a[i] == '1'){
                if(carry){
                    ans.push_back('1');
                }
                else{
                    ans.push_back('0');
                    carry = 1;
                }
            }
            else if(a[i] == b[i] && a[i] == '0'){
                if(carry){
                    ans.push_back('1');
                    carry = 0;
                }
                else{
                    ans.push_back('0');
                }
            }
            else{
                if(carry){
                    ans.push_back('0');
                    carry = 1;
                }
                else{
                    ans.push_back('1');
                }
            }
        }
        if(carry)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string addBinary(string a, string b) {
        int size_a = a.size();
        int size_b = b.size();
        if(size_a == size_b){
            return add(a, b);
        }
        else if(size_a > size_b){
            reverse(b.begin(), b.end());
            for(int i = 0; i < size_a - size_b; i++){
                b.push_back('0');
            }
            reverse(b.begin(), b.end());
        }
        else{
            reverse(a.begin(), a.end());
            for(int i = 0; i < size_b - size_a; i++){
                a.push_back('0');
            }
            reverse(a.begin(), a.end());
        }
        return add(a, b);
    }
};