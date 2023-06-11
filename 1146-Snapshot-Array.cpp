class SnapshotArray {
    vector<unordered_map<int,int>> _snaps = {{}};
public:
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        _snaps[_snaps.size()-1][index] = val;
    }
    
    int snap() {
        _snaps.push_back({});
        return _snaps.size()-2;
    }
    
    int get(int index, int snap_id) {
        for(int i=snap_id; i>=0; i--)
            if(_snaps[i].count(index)) 
                return _snaps[i][index];
        
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
