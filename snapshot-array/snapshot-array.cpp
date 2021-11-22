class SnapshotArray {
private:
    vector<pair<int, int>>changeList;
    int snapId;
    vector<int>snapList;
public:
	SnapshotArray(int length) {
		snapId = 0;
	}

	void set(int index, int val) {
		changeList.push_back(make_pair(index, val));
	}

	int snap() {
		snapList.push_back(changeList.size());
		return snapList.size()-1;
	}

	int get(int index, int snap_id) {
		int start = snapList[snap_id];
		for (int i = start - 1; i >= 0; i--) {
			if (changeList[i].first == index) {
				return changeList[i].second;
			}
		}
		return 0;
	}
};
