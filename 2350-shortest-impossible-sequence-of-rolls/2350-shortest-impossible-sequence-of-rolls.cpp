class Solution {
private:
    set<int> dices;
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int res = 1;
        for (auto r : rolls) {
            dices.insert(r);
            if (dices.size() == k) {
                res++;
                dices.clear();
            }
        }
        return res;
    }
};