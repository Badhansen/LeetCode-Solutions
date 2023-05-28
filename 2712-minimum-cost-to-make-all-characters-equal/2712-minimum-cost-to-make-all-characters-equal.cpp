class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        long long answer = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                answer += min(i, n - i);
            }
        }
        return answer;
    }
};

/*
    Take ::  000000100
For this test case first it is feasile to make last two zeroes flip
i.e
            000000111
And then make those three one's again flip:
            000000000
Total step required : 2+3,
*/