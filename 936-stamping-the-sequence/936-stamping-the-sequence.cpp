class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        auto total_stamp = 0, turn_stamp = -1;
        while(turn_stamp){ // will run until and unless there is some replacement in the target. 
            turn_stamp = 0; // initalize to zero to insure there is some changes in the iteration or it will go // to  infinite loop
            for(int sz = stamp.size(); sz>0; --sz){ // sz insure how much lenght of stamp we go for and rest will // replaced with '?'.
                for(auto i =0;i<=stamp.size()-sz;i++){ // for iterating over all the position of the stamp.
                    auto new_stamp = string(i, '?') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '?');
                    // new_stamp is creating new stamp with some portion with '?' and some portion actual target 
                    // characters.
                    auto pos = target.find(new_stamp); // find the specific sequence in whole string.
                    while(pos != string::npos){ // while loop ensure whole matching subsequence convert to '?'.
                        res.push_back(pos); // storing the initial position as need to return;
                        turn_stamp += sz;
                        fill(begin(target) + pos, begin(target) + pos + stamp.size() , '?'); // converting 
                        // character to '?' of target.
                        pos = target.find(new_stamp); // finding next substring in target.
                    }
                }
                
            }
            total_stamp += turn_stamp; // storing count which insure that how much characters are replaced.
        }
        reverse(begin(res), end(res)); 
        return total_stamp == target.size() ? res : vector<int>(); //checking if the all the characters are 
        // convered to '?'
    }
};