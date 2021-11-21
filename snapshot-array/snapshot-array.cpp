#define MAX_SNAP 50005

class SnapshotArray {
private:
    unordered_map<int, int> memo[MAX_SNAP];
    int snapIndex;
public:
    SnapshotArray(int length) {
        snapIndex = 0;
    }
    
    void set(int index, int val) {
        memo[snapIndex][index] = val;
    }
    
    int snap() {
        snapIndex++;
        return snapIndex - 1;
    }
    
    int get(int index, int snap_id) {
        while(snap_id >= 0){
            if(memo[snap_id].count(index)){
                return memo[snap_id][index];
            }
            snap_id--;
        }
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */