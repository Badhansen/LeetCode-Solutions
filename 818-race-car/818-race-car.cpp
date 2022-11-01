// @Author: KING-SEN

class Solution {
public:
    int racecar(int target) {
        std::queue<std::array<int, 2>> que;
        std::map<std::array<int, 2>, bool> discovered;
        que.push({0, 1});
        discovered.insert({{0, 1}, true});
        int level = 0;
        while (!que.empty()) {
            int que_size = que.size();
            while (que_size--) {
                auto node = que.front();
                que.pop();
                if (node[0] == target) {
                    return level;
                }
                for (int i = 0; i < 2; i++) {
                    int position = node[0];
                    int speed = node[1];
                    if (i == 0) {
                        position += speed;
                        speed *= 2;
                    } else {
                        speed = speed > 0 ? -1 : 1;
                    }
                    if (position < 0 || position > 2 * target) {
                        continue;
                    }
                    if (discovered.insert({{position, speed}, true}).second) {
                        que.push({position, speed});
                    }
                }
                
            }
            level++;
        }
        return level;
    }
};
// Time : O(T log T)
// Space : O(T log T)

// Explanation: https://www.youtube.com/watch?v=p8N4iKiLnnU&t=1242s