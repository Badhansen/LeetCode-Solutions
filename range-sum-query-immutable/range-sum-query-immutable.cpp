class NumArray {
private:
    vector<int> csum;
public:
    NumArray(vector<int>& nums) {
        int len = nums.size();
        csum.resize(len + 1, 0);
        for(int i = 1; i <= len; i++){
            csum[i] = csum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return csum[right + 1] - csum[left];
    }
};
