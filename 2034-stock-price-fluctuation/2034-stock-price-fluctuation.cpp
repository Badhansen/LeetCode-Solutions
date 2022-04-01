class StockPrice {
private:
    map<int, int> rate;
    multiset<int> prices;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(rate.count(timestamp)){
            auto itPos = prices.find(rate[timestamp]);
            prices.erase(itPos);
        }
        prices.insert(price);
        rate[timestamp] =  price;
    }
    
    int current() {
        return rate.rbegin()->second;
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */