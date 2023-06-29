class Solution {
private:
    struct Node {
        int x, y, distance, keys;
        Node(int i, int j, int d, int k) {
            x = i, y = j, distance = d, keys = k;
        }
    }; 
public:
    vector<vector<int>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int x, y, allKeys = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '@') {
                    x = i, y = j;
                } else if (islower(grid[i][j])) {
                    allKeys = (allKeys << 1) + 1;
                }
            } 
        }
        queue<Node> qt;
        qt.push(Node(x, y, 0, 0));
        
        vector<vector<vector<bool>>> visited(rows, vector<vector<bool>>(cols, vector<bool>(64, false)));
        while (!qt.empty()) {
            Node node = qt.front();
            int dist = node.distance;
            qt.pop();
            char c = grid[node.x][node.y];
            int keys = node.keys;
            if (islower(c)) {
                int key = 1 << (c - 'a');
                keys |= key;
            }
            if (visited[node.x][node.y][keys] == true) continue;
            visited[node.x][node.y][keys] = true;
            if (keys == allKeys) {
                return dist;
            }
            for (auto d : dirs) {
                int nr = node.x + d[0];
                int nc = node.y + d[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != '#') {
                    if (isupper(grid[nr][nc])) {
                        int door = 1 << (grid[nr][nc] - 'A');
                        if ((keys & door) == 0) {
                            continue;
                        }
                    }
                    qt.push(Node(nr, nc, dist + 1, keys));
                }
            }
                
        }
        return -1;
    }
};

/*
[".@aA"]
[
"@...a",
".###A",
"b.BCc"]
*/