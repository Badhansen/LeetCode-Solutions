// @Author: KING-SEN
// 1 last try

class StockPrice {
private:
    map<int, int> rate;
    multiset<int> prices;
public:
    StockPrice() {
        
    }
    // O(5 log N ~ log N)
    void update(int timestamp, int price) { 
        if(rate.count(timestamp)){
            auto itPos = prices.find(rate[timestamp]);
            prices.erase(itPos);
        }
        prices.insert(price);
        rate[timestamp] =  price;
    }
    // O(1)
    int current() { 
        return rate.rbegin()->second;
    }
    // O(1)
    int maximum() { 
        return *prices.rbegin();
    }
    // O(1)
    int minimum() { 
        return *prices.begin();
    }
};

// Time: O(log N), N = total number of elements
// Space: O(N)

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */