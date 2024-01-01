// @Author: KING-SEN
// Problem Link: https://leetcode.com/problems/finding-mk-average/

enum class Positions {
    kBottom = 0,
    kMiddle,
    kTop,
};

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
                removingValue(removedValue, Positions::kTop);
            } else if (middle.find(removedValue) != middle.end()) {
                removingValue(removedValue, Positions::kMiddle);
                int value = removeSmallest(kTop);
                addingValue(value, Positions::kMiddle);
            } else {
                removingValue(removedValue, Positions::kBottom);
                int value = removeSmallest(kTop);
                addingValue(value, Positions::kMiddle);
                
                value = removeSmallest(middle);
                sum -= value; // Already removed the value so don't calling the removingValue function, just decrement the sum
                addingValue(value, Positions::kBottom);
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
        addingValue(num, Positions::kBottom);
        if (kBottom.size() > k) {
            int value = removeLargest(kBottom);
            addingValue(value, Positions::kMiddle);
            if (middle.size() > m - 2 * k) {
                value = removeLargest(middle);
                sum -= value; // For middle as we have already deleted the value from the set, so we are not calling the removingValue function
                addingValue(value, Positions::kTop);
            }
        }
    }
    void addingValue(int value, enum Positions pos) {
        switch (pos) {
            case Positions::kBottom:
                kBottom.insert(value);
                break;
            case Positions::kMiddle:
                middle.insert(value);
                sum += value;
                break;
            case Positions::kTop:
                kTop.insert(value);
                break;
        }
    }
    void removingValue(int value, enum Positions pos) {
        switch (pos) {
            case Positions::kBottom:
                kBottom.erase(kBottom.find(value));
                break;
            case Positions::kMiddle:
                middle.erase(middle.find(value));
                sum -= value;
                break;
            case Positions::kTop:
                kTop.erase(kTop.find(value));
                break;
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