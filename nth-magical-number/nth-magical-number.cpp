// @Author: KING-SEN
// Programming Language Used: C++
const int mod = 1e9 + 7;

class Solution {
private:
    long long lcm;
public:
    long long totalDiv(long long n, long long a, long long b){
        return (n / a) + (n / b) - (n / lcm);
    }
    int nthMagicalNumber(int n, int a, int b) {
        lcm = (a / __gcd(a, b)) * b;
        long long start = 1, end = 2e18, mid, ans, result;
        while(start <= end){
            mid = (start + end) / 2;
            ans = totalDiv(mid, a, b);
            if(ans < n){
                start = mid + 1;
            }
            else{
                result = mid % mod;
                end = mid - 1;
            }
        }
        return result;
    }
};

// Time Complexity: O(log N), here N = Size of search space
// Space Complexity: O(1)