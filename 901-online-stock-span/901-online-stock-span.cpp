class StockSpanner {
private:
    stack<pair<int, int>> stack;
public:
    StockSpanner() {
        // pass
    }
    int next(int price) {
        int res = 1;
        while (!stack.empty() && stack.top().first <= price) {
            res += stack.top().second;
            stack.pop();
        }
        stack.push({price, res});
        return res;
    }
    ~StockSpanner() {
        while(!stack.empty()){
            stack.pop();
        }
    }
};

/*
class StockSpanner {
private:
    stack<int> stack;
    vector<int> prices;
    int index;
public:
    StockSpanner() {
        index = 0;
    }
    int next(int price) {
        prices.push_back(price);
        while(!stack.empty() && price >= prices[stack.top()]){
            stack.pop();
        }
        int res = stack.empty() ? index + 1 : index - stack.top();
        stack.push(index++);
        return res;
    }
    ~StockSpanner() {
        while(!stack.empty()){
            stack.pop();
        }
        prices.clear();
    }
};
*/

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
/*
0    1  2  3  4  5  6
[100,80,60,70,60,75,85]
85 75 70 60 
0  1 2 3 4 5 6
[1,1,1,2,1,4,6]
*/