// @Author: KING-SEN
// Problem Link: https://leetcode.com/problems/finding-mk-average/

class MKAverage {
private:
    int m, k;
    long long sum;
    
    queue<int> stream;
    multiset<int> kBottom;
    multiset<int> middle;
    multiset<int> kTop;
public:
    MKAverage(int m, int k) {
        this->m = m, this->k = k;
        sum = 0;
    }
    
    void addElement(int num) {
        stream.push(num);
        
        if (stream.size() > m) {
            int removedValue = stream.front();
            stream.pop();
            if (kTop.find(removedValue) != kTop.end()) {
                kTop.erase(kTop.find(removedValue));
            } else if (middle.find(removedValue) != middle.end()) {
                middle.erase(middle.find(removedValue));
                sum -= removedValue;
                int value = removeSmallest(kTop);
                middle.insert(value);
                sum += value;
            } else {
                kBottom.erase(kBottom.find(removedValue));
                int value = removeSmallest(kTop);
                middle.insert(value);
                sum += value;
                value = removeSmallest(middle);
                sum -= value;
                kBottom.insert(value);
            }
        }
        
        add(num);
    }
    
    int calculateMKAverage() {
        if (stream.size() < m) {
            return -1;
        }
        return sum / (int)middle.size();
    }
private:
    void add(int num) {
        kBottom.insert(num);
        if (kBottom.size() > k) {
            int value = removeLargest(kBottom);
            middle.insert(value);
            sum += value;
            if (middle.size() > m - 2 * k) {
                value = removeLargest(middle);
                sum -= value;
                kTop.insert(value);
            }
        }
    }
    int removeSmallest(multiset<int>& set) {
        auto smallest = set.begin();
        int result = *smallest;
        set.erase(smallest);
        return result;
    }
    int removeLargest(multiset<int>& set) {
        auto largest = --set.end();
        int result = *largest;
        set.erase(largest);
        return result;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */