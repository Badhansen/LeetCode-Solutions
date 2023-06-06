static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > qt;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i = 0; i < nums.size(); i++){
            qt.push(nums[i]);
            if(qt.size() == K + 1) qt.pop();
        }
    }
    
    int add(int val) {
        qt.push(val);
        if(qt.size() == K + 1) qt.pop();
        return qt.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */