#define MAX_SNAP 50005

class SnapshotArray {
private:
    map<int, map<int, int>> memo;
    int snapIndex;
public:
    SnapshotArray(int length) {
        for(int i = 0; i < length; i++){
            map<int, int> mp;
            mp[0] = 0;
            memo[i] = mp;
        }
        snapIndex = 0;
    }
    
    void set(int index, int val) {
        memo[index][snapIndex] = val;
    }
    
    int snap() {
        snapIndex++;
        return snapIndex - 1;
    }
    
    int get(int index, int snap_id) {
        auto pos = memo[index].upper_bound(snap_id);
        pos--;
        return pos->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */