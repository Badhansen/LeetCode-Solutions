/*
    pig     max_bucket      trial
    1           ? = 2         1
    1           ? = 3         2
    1           ? = 4         3
    ............................
    
    so (p, t) -> t + 1 max_bucket for 1 pig
    now for n pig we can have max_bucket
    => (t + 1) * (t + 1) ........ n times
    => (t + 1) ^ n = max_bucket
    => n * log(t + 1) = log(max_bucket)
    => n = log(max_bucket) / log(t + 1)
*/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log2(buckets) / log2(minutesToTest / minutesToDie + 1));
    }
};