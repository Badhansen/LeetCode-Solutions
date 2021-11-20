// Programming Language Used: C++

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> seen;
        vector<int> answer;
        
        for(auto &num : changed){
            seen[num]++;
        }
        
        sort(changed.begin(), changed.end());
        
        for(int i = 0; i < changed.size(); i++){
            if(seen[changed[i]]){
                seen[changed[i]]--;
                if(seen[changed[i] * 2]){
                    seen[changed[i] * 2]--;
                    answer.push_back(changed[i]);
                }
                else
                    return {};
            }
        }
        
        return answer;
    }
};

// Time Complexity: O(N log N), Here N = Length of the array.
// Space Complexity: O(N), Here we use answer and seen for return results and count the occurances of the array elements
