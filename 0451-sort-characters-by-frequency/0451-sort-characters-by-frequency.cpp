// Fast I/O; 4 ms
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

#define MAX 100001
struct Node{
    int freq;
    char ch;
    bool operator < (const Node &A) const{
        return A.freq > freq;
    } 
};
class Heap{
    Node tree[MAX];
    int size;
public:
    Heap(){
        size = 0;
    }
    bool empty(){
        return !size;
    }
    Node top(){
        return tree[1];
    }
    void push(const Node &x){
        tree[++size] = x;
        for(int i = size; i > 1; i /= 2){
            if(tree[i / 2] < tree[i]) 
                swap(tree[i], tree[i / 2]);
        }
    }
    void pop(){
        tree[1] = tree[size--];
        for(int i = 1; i * 2 <= size;){
            int k = i * 2 + 1;
            if(i * 2 == size || tree[i * 2 + 1] < tree[i * 2]){
                k = i * 2;
            }
            if(tree[i] < tree[k]){
                swap(tree[k], tree[i]);
                i = k;
            }
            else break;
        }
    }
};
class Solution {
public:
    string frequencySort(string s) {
        int cnt[257];
        Heap hr;
        for(int i = 0; i < 256; i++){
            cnt[i] = 0;
        }
        for(int i = 0; i < s.size(); i++){
            cnt[s[i]]++;
        }
        for(int i = 0; i < 256; i++){
            if(cnt[i]){
                Node p;
                p.freq = cnt[i];
                p.ch = char(i);
                hr.push(p);
            }
        }
        string str = "";
        while(hr.empty() == false){
            Node p = hr.top();
            hr.pop();
            for(int i = 0; i < p.freq; i++){
                str.push_back(p.ch);
            }
            
        }
        return str;
    }
};