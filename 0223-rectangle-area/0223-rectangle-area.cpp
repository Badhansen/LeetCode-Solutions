class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs(ax1 - ax2) * abs(ay1 - ay2);
        int area2 = abs(bx1 - bx2) * abs(by1 - by2);
        // calculate x overlap
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int x_overlap = right - left;

        // calculate y overlap
        int top = min(ay2, by2);
        int bottom = max(ay1, by1);
        int y_overlap = top - bottom;
        int diff = 0;
        if (x_overlap > 0 && y_overlap > 0) {
            diff = x_overlap * y_overlap;
        }
        return area1 + area2 - diff;
    }
};