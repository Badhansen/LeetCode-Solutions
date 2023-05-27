class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        multiset<int> window;
        vector<double> answer;
        
        for (int i = 0; i < k; i++) {
            window.insert(nums[i]);
        }
        auto it = next(window.begin(), (k - 1) / 2); 
        for (int i = k; i <= n; i++) {            
            double median = (k & 1) ? *it : (1.0 * *it + *next(it)) / 2.00;
            answer.push_back(median);
            if (i == n) {
                break;
            }
            // Insert nums[i]. if nums[i] > mid then mid iterator would not changed. but if I insert a smaller element it will incrase
            window.insert(nums[i]);
            if (nums[i] < *it)
                it--;

            // Erase nums[i-k]. if the erased element is smaller or equal the mid then it will decrease it pointer so we have to increase it
            if (nums[i-k] <= *it)
                it++;
            window.erase(window.lower_bound(nums[i - k]));
        }
        return answer;
    }
};