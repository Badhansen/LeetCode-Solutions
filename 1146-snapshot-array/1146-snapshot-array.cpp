class SnapshotArray {
private:
    map<int, map<int, int>> memo;
    int snapIdx;
public:
	SnapshotArray(int length) {
		snapIdx = 0;
	}
	void set(int index, int val) {
		memo[index][snapIdx] = val;
	}
	int snap() {
		return snapIdx++;
	}
	int get(int index, int snap_id) {
		auto it = memo[index].upper_bound(snap_id);
        return it == memo[index].begin() ? 0 : prev(it)->second;
	}
};

/*
    Complexity analysis
    Assuming "n" is the number of "set + snap" operations, and "m" is the number of get operations:

    Note: for the complexity analysis, we consider set + snap as one operation. Otherwise, neither set nor snap alone increases the number of values we need to consider for the get operation.

    Time Complexity:
    Set: O(1) single operation, and total O(n).
    Get: O(log n) for a single operation, and total O(m log n).
    Space Complexity: O(n)
*/
