//@Author: KING-SEN
class FreqStack {
public:
    unordered_map<int, int> frequency;
    unordered_map<int, vector<int>> element;
    int max_frequency;
    FreqStack() {
        max_frequency = 0;
    }
    
    void push(int val) {
        int count = frequency[val]++;
        element[count].emplace_back(val);
        max_frequency = max(max_frequency, count);
    }
    
    int pop() {
        int answer = element[max_frequency].back();
        element[max_frequency].pop_back();
        frequency[answer]--;
        if(element[max_frequency].empty()) max_frequency--;
        return answer;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */