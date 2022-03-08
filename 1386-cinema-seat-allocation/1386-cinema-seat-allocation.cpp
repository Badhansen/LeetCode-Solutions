//@Author: KING-SEN
/*
class Solution {
private:
    map<int, set<int>> seat;
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<int> left = {2, 3, 4, 5};
        vector<int> right = {6, 7, 8, 9};
        vector<int> middle = {4, 5, 6, 7};
        for(auto s : reservedSeats){
            if(find(left.begin(), left.end(), s[1]) != left.end()){
                seat[s[0]].insert(0);
            }
            if(find(middle.begin(), middle.end(), s[1]) != middle.end()){
                seat[s[0]].insert(1);
            }
            if(find(right.begin(), right.end(), s[1]) != right.end()){
                seat[s[0]].insert(2);
            }
        }
        int ans = 2 * n;
        for(auto s : seat){
            if(s.second.size() == 3){
                ans -= 2;
            }
            else{
                ans--;
            }
        }
        return ans;
    }
};
*/

//@Author: KING-SEN

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> seat;
        for(auto &s : reservedSeats){
            seat[s[0]] = seat[s[0]] | (1 << (s[1] - 1));
        }
        int res = 0;
        for(auto &[key, b] : seat){
            if(!(b & 0b0111111110)){
                res += 2;
            }
            else if(!(b & 0b0111100000) || !(b & 0b0000011110) || !(b & 0b0001111000)){
                res++;
            }
        }
        return res + (n - seat.size()) * 2;
    }
};
