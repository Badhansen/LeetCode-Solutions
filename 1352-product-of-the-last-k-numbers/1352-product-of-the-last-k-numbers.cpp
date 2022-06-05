class ProductOfNumbers {
private:
    vector<int> product = {1};
public:
    ProductOfNumbers() {
        // pass
    }
    
    void add(int num) {
        if(num) product.push_back(product.back() * num);
        else product = {1};
    }
    
    int getProduct(int k) {
        if(k < product.size()){
            return product.back() / product[product.size() - k - 1];
        }
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */