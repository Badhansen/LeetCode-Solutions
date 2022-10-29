class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long total_mass = mass;
        for (auto ast : asteroids) {
            if (total_mass >= ast) {
                total_mass += ast;
            } else {
                return false;
            }
        }
        return true;
    }
};