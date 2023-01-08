class Solution {
public:
    int maxPointOnSameLine(vector<vector<int>>& points) {
        int N = points.size();
        if (N < 2)
            return N;
        int maxPoint = 0;
        int curMax, overlapPoints, verticalPoints;
        map<pair<int, int>, int> slopeMap;
        for (int i = 0; i < N; i++) {
            curMax = overlapPoints = verticalPoints = 0;
            for (int j = i + 1; j < N; j++) {
                if (points[i] == points[j]) {
                    overlapPoints++;
                } else if (points[i][0] == points[j][0]) {
                    verticalPoints++;
                } else {
                    int yDif = points[j][1] - points[i][1];
                    int xDif = points[j][0] - points[i][0];
                    int g = __gcd(xDif, yDif);
                    yDif /= g;
                    xDif /= g;
                    slopeMap[make_pair(yDif, xDif)]++;
                    curMax = max(curMax, slopeMap[make_pair(yDif, xDif)]);
                }
                curMax = max(curMax, verticalPoints);
            }
            maxPoint = max(maxPoint, curMax + overlapPoints + 1);
            slopeMap.clear();
        }
        return maxPoint;
    }
    int maxPoints(vector<vector<int>>& points) {
        return maxPointOnSameLine(points);
    }
};