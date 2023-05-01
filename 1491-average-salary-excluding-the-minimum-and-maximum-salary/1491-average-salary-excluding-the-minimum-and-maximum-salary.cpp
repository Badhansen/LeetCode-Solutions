class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        double sum = accumulate(salary.begin(), salary.end(), 0);
        int minSalary = *min_element(salary.begin(), salary.end());
        int maxSalary = *max_element(salary.begin(), salary.end());
        sum -= (minSalary + maxSalary);
        return sum / (n - 2);
    }
};