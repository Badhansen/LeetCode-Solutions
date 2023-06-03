class Solution {
public:
    struct Node {
        int data, row, col;
        Node(int value, int r, int c) : data(value), row(r), col(c) {}
    };
    struct comparator {
        bool operator()(const Node& a, const Node& b) {
            return a.data > b.data;
        }  
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int row = nums.size();
        int currMin = INT_MAX, currMax = INT_MIN, minRange = INT_MAX;
        priority_queue<Node, vector<Node>, comparator> minHeap;
        for (int i = 0; i < row; i++) {
            currMax = max(currMax, nums[i][0]);
            Node temp(nums[i][0], i, 0);
            minHeap.push(temp);
        }
        int start = currMin, end = currMax;
        while (true) {
            Node m = minHeap.top();
            minHeap.pop();
            currMin = m.data;
            if (currMax - currMin < minRange) {
                start = currMin;
                end = currMax;
                minRange = currMax - currMin;
            }
            if (m.col + 1 == nums[m.row].size()) {
                break;
            }
            Node next(nums[m.row][m.col + 1], m.row, m.col + 1);
            minHeap.push(next);
            if (next.data > currMax) {
                currMax = next.data;
            }
        }
        return {start, end};
    }
};

// Time: O(N log K)
// Space: O(K)
