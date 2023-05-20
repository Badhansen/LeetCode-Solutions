// @Author: KING-SEN

class Solution {
public:
    int row = 0, column = 0;
    map<string, bool> dp;
    bool Dfs(int r, int c, int sum, vector<vector<int>>& grid) {
        if (r >= row || c >= column) {
            return false;
        }
        string key = to_string(r) + "|" + to_string(c) + "|" + to_string(sum);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        sum += grid[r][c] == 1 ? 1 : -1;
        if (r == row - 1 && c == column - 1) {
            return sum == 0;
        }
        return dp[key] = Dfs(r + 1, c, sum, grid) || Dfs(r, c + 1, sum, grid);
    }
    bool isThereAPath(vector<vector<int>>& grid) {
        row = grid.size();
        column = grid[0].size();
        if ((row + column - 1) % 2 != 0) {
            return false;
        }
        return Dfs(0, 0, 0, grid);
    }
};
/*
Time complexity of naive solution

The time complexity of the given solution is O(2^(row + column)), and the space complexity is O(row + column).

In the Dfs function, the recursive calls are made for two directions: moving down (Dfs(r + 1, c, sum, grid)) and moving right (Dfs(r, c + 1, sum, grid)). In the worst case, each call can branch out into two recursive calls, resulting in an exponential number of recursive calls.

Since the grid has dimensions row and column, the maximum depth of the recursion can be row + column. For each level of recursion, there are two possible recursive calls. Therefore, the total number of recursive calls becomes 2^(row + column), which represents the number of possible paths in the grid.

As for the space complexity, the recursive calls utilize the call stack. The maximum depth of the recursion is row + column, so the space required for the call stack is O(row + column).

In addition to the call stack, the solution does not require any additional space that scales with the input size. Hence, the space complexity is O(row + column).

In the updated solution, an additional `dp` map is introduced to memoize the results of subproblems. This allows for avoiding redundant computations and improving the overall efficiency of the algorithm.

The time complexity of the updated solution is O(row * column), and the space complexity is O(row * column).

Here's an explanation of the complexities: Dp solution

- Time Complexity: In the `Dfs` function, before making any recursive calls, the function checks if the current state (represented by `r`, `c`, and `sum`) has already been computed and stored in the `dp` map. If the state is found in the map, the function returns the memoized result in constant time.

   Therefore, the maximum number of unique states that need to be computed is limited by the number of cells in the grid, which is `row * column`. Each state computation takes constant time.

   As a result, the overall time complexity is O(row * column).

- Space Complexity: The additional space used by the updated solution includes the `dp` map and the recursion stack.

   The `dp` map stores the computed results for unique states. The maximum number of unique states is bounded by the number of cells in the grid, which is `row * column`. Therefore, the space required for the `dp` map is O(row * column).

   Regarding the recursion stack, the maximum depth of the recursion is limited by `row + column`. Each recursive call requires additional space on the stack. Therefore, the space required for the recursion stack is O(row + column).

   In total, the space complexity is O(row * column) due to the `dp` map, and the recursion stack requires additional O(row + column) space.

It's worth noting that the introduction of memoization in the form of the `dp` map improves the time complexity from exponential to polynomial, significantly reducing the number of redundant computations.
*/