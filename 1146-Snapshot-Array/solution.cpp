class SnapshotArray {
 public:
  SnapshotArray(int length) : snaps(length) {
    for (auto& snap : snaps)
      snap.emplace_back(0, 0);
  }

  void set(int index, int val) {
    auto& [lastSnapId, lastVal] = snaps[index].back();
    if (lastSnapId == snap_id)
      lastVal = val;
    else
      snaps[index].emplace_back(snap_id, val);
  }

  int snap() {
    return snap_id++;
  }

  int get(int index, int snap_id) {
    const vector<pair<int, int>>& snap = snaps[index];
    auto it = lower_bound(begin(snap), end(snap), make_pair(snap_id + 1, 0));
    return prev(it)->second;
  }

 private:
  // snaps[i] := [(snap_id, val)]
  vector<vector<pair<int, int>>> snaps;
  int snap_id = 0;
};


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */