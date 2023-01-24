class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<array<int, 2>> cells(n * n + 1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        int index = 1;
        for (int r = n - 1; r >= 0; r--) {
            for (int c : columns) {
                cells[index++] = {r, c};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        queue<int> que;
        que.push(1);
        dist[1] = 0;
        while (!que.empty()) {
            int curr = que.front();
            que.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, col] = cells[next];
                int next_dist = board[row][col] == -1 ? next : board[row][col];
                if (dist[next_dist] == -1) {
                    dist[next_dist] = dist[curr] + 1;
                    que.push(next_dist);
                }
            }
        }
        return dist[n * n];
    }
};

/*
[

[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,35,-1,-1,13,-1],
[-1,-1,-1,-1,-1,-1],
[-1,15,-1,-1,-1,-1]

]
*/