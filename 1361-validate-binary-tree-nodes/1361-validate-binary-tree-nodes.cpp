class Solution {
public:
    bool dfs(int u, vector<int>& leftChild, vector<int>& rightChild, set<int> &visited) {
        if (u == -1) {
            return true;
        }
        if (visited.count(u)) {
            return false;
        }
        visited.insert(u);
        return dfs(leftChild[u], leftChild, rightChild, visited)
            && dfs(rightChild[u], leftChild, rightChild, visited);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        set<int> hasParents(leftChild.begin(), leftChild.end());
        for (auto r : rightChild) {
            hasParents.insert(r);
        }
        hasParents.erase(-1);
        if (hasParents.size() == n) {
            return false;
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (!hasParents.count(i)) {
                root = i;
                break;
            }
        }
        set<int> visited;
        return dfs(root, leftChild, rightChild, visited) && visited.size() == n;
    }
};