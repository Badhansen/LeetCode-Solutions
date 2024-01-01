class MKAverage {
private:
    int m, k;
    long long sum;
    
    queue<int> stream;
    multiset<int> kLeft;
    multiset<int> avg;
    multiset<int> kRight;
public:
    MKAverage(int m, int k) {
        this->m = m, this->k = k;
        sum = 0;
    }
    
    void addElement(int num) {
        stream.push(num);
        if (stream.size() > m) {
            // remove the value -> num
            int removeValue = stream.front();
            stream.pop();
            
            if (kLeft.size() > 0 && (*kLeft.rbegin()) >= removeValue) {
                kLeft.erase(kLeft.find(removeValue));
            } else if (kRight.size() > 0 && (*kRight.begin()) <= removeValue) {
                kRight.erase(kRight.find(removeValue));
            } else {
                avg.erase(avg.find(removeValue));
                sum -= removeValue;
            }
        }
        
        // add value to the multiset
        if (kLeft.size() > 0 && (*kLeft.rbegin()) >= num) {
            kLeft.insert(num);
        } else if (kRight.size() > 0 && (*kRight.begin()) < num) {
            kRight.insert(num);
        } else {
            avg.insert(num);
            sum += num;
        }
        
        // balancing the tree size after adding
        if (kLeft.size() > k) {
            int movingValue = removeLargest(kLeft);
            avg.insert(movingValue);
            sum += movingValue;
        } else if (kRight.size() > k) {
            int movingValue = removeSmallest(kRight);
            avg.insert(movingValue);
            sum += movingValue;
        }
        
        if (avg.size() > m - 2 * k) {
            if (kLeft.size() < k) {
                int movingValue = removeSmallest(avg);
                sum -= movingValue;
                kLeft.insert(movingValue);
            } else if (kRight.size() < k) {
                int movingValue = removeLargest(avg);
                sum -= movingValue;
                kRight.insert(movingValue);
            }
        }
        
    }
    
    int calculateMKAverage() {
        if (stream.size() < m) {
            return -1;
        }
        return sum / (int)avg.size();
    }
private:
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