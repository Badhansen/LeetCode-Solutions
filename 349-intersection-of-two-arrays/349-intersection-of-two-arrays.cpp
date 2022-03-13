/*
    This is a Facebook interview question.
    They ask for the intersection, which has a trivial solution using a hash or a set.

    Then they ask you to solve it under these constraints:
    O(n) time and O(1) space (the resulting array of intersections is not taken into consideration).
    You are told the lists are sorted.

    Cases to take into consideration include:
    duplicates, negative values, single value lists, 0's, and empty list arguments.
    Other considerations might include
    sparse arrays.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
        sort(num1.begin(), num1.end()); // assume sorted 
        sort(num2.begin(), num2.end()); // assume sorted
        vector<int> answer;
        int num1Len = num1.size();
        int num2Len = num2.size();
        int lIdx = 0, rIdx = 0;
        while(lIdx < num1Len && rIdx < num2Len){
            int left = num1[lIdx], right = num2[rIdx];
            if(left == right){
                answer.push_back(left);
                while(lIdx < num1Len && left == num1[lIdx]){
                    lIdx++;
                }
                while(rIdx < num2Len && right == num2[rIdx]){
                    rIdx++;
                }
            }
            else if(right > left){
                lIdx++;
            }
            else{
                rIdx++;
            }
        }
        return answer;
    }
};