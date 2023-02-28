/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {
        bool all_same = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[r][c] != grid[r + i][c + j]) {
                    all_same = false;
                    break;
                }
            }
        }
        if (all_same) {
            return new Node(grid[r][c], true);
        }
        n = n / 2;
        Node* topleft = dfs(grid, n, r, c);
        Node* topright = dfs(grid, n, r, c + n);
        Node* bottomleft = dfs(grid, n, r + n, c);
        Node* bottomright = dfs(grid, n, r + n, c + n);
        
        return new Node(0, false, topleft, topright, bottomleft, bottomright);
    }
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }
};