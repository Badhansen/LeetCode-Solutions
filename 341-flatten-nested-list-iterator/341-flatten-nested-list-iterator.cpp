/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    queue<int> items;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto l : nestedList){
            dfs(l);
        }
    }
    
    int next() {
        int ret = items.front();
        items.pop();
        return ret;
    }
    
    bool hasNext() {
        return !items.empty();
    }
    
    void dfs(NestedInteger &lst){
        if(lst.isInteger()){
            items.push(lst.getInteger());
            return;
        }
        for(auto l : lst.getList()){
            dfs(l);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */