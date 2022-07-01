// monotonic stack solution
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.push_back(0); // append a zero at the end so that we can pop all elements from the stack and calculate the corresponding areas
        int N = A.size(), ans = 0;
        stack<int> s; // strictly-increasing mono-stack
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[i] <= A[s.top()]) { // Take `A[i]` as the right edge
                int height = A[s.top()]; // Take the popped element as the height
                s.pop();
                int left = s.size() ? s.top() : -1; // Take the element left on the stack as the left edge
                ans = max(ans, (i - left - 1) * height);
            }
            s.push(i);
        }
        return ans;
    }
};

// Time: O(N)
// Space: O(N)