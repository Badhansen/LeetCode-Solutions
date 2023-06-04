class Solution {
private:
    unordered_map<string, bool> deadlock, visited;
public:
    string GetForwardMove(string move, int index) {
        int ndigit = (move[index] - '0' + 1 + 10) % 10;
        string fmove = move.substr(0, index) + to_string(ndigit) + move.substr(index + 1);
        return fmove;
    }
    string GetBackwardMove(string move, int index) {
        int ndigit = (move[index] - '0' - 1 + 10) % 10;
        string bmove = move.substr(0, index) + to_string(ndigit) + move.substr(index + 1);
        return bmove;
    }
    int openLock(vector<string>& deadends, string target) {
        for (auto &el : deadends) {
            deadlock[el] = true;
        }
        if (deadlock.count("0000") || deadlock.count(target)) {
            return -1;
        }
        queue<string> queue;
        queue.push("0000");
        visited["0000"] = true;
        int turns = 0;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                string move = queue.front();
                queue.pop();
                if (move == target) {
                    return turns;
                }
                for (int index = 0; index < 4; index++) {
                    string fmove = GetForwardMove(move, index);
                    string bmove = GetBackwardMove(move, index);
                    
                    if (!deadlock.count(fmove) && !visited.count(fmove)) {
                        queue.push(fmove);
                        visited[fmove] = true;
                    }
                    if (!deadlock.count(bmove) && !visited.count(bmove)) {
                        queue.push(bmove);
                        visited[bmove] = true;
                    }
                }
            }
            turns++;
        }
        return -1;
    }
};