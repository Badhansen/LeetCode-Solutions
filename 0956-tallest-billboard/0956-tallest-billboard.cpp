// not my code
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        std::unordered_map<int, int> dp;
        dp[0] = 0; // Initialize the dynamic programming dictionary with 0 as the initial state
        for (int x : rods) { // Iterate over each rod length in the input vector
            unordered_map<int, int> nxt = dp; // Create a copy of the current dynamic programming dictionary
            for (const auto& [d, y] : dp) { // Iterate over the key-value pairs in the dynamic programming dictionary
                // Put the rod x in the tall side and update the maximum height difference
                nxt[d + x] = max(nxt[d + x], y);
                // Put the rod x in the low side and update the maximum height
                nxt[abs(d - x)] = max(nxt[abs(d - x)],y + min(d, x));
            }
            dp = nxt; // Update the dynamic programming dictionary with the updated values
        }
        return dp[0]; // Return the maximum height of the billboard
    }
};