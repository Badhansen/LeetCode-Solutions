class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        int length = asteroids.size();
        for (int i = 0; i < length; i++) {
            bool blows = false;
            while (result.size() && asteroids[i] < 0 && result.back() > 0 && !blows) {
                if (abs(asteroids[i]) < result.back()) {
                    blows = true;
                } else {
                    if (abs(asteroids[i]) == result.back()) {
                        blows = true;
                        result.pop_back();
                    } else {
                        result.pop_back();
                    }
                }
            }
            if (!blows) {
                result.push_back(asteroids[i]);
            }
        }
        return result;
    }
};