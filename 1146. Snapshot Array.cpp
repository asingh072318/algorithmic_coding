## https://leetcode.com/problems/snapshot-array/
class SnapshotArray {
public:
    vector<map<int,int>> sa;
    int snap_id=0;
    SnapshotArray(int length) {
        sa.resize(length);
        for(int i = 0; i < length; i++)
            sa[i][0] = 0;
    }
    
    void set(int index, int val) {
        sa[index][snap_id] = val;
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        if(sa[index].find(snap_id) == sa[index].end()){
            auto it = --sa[index].lower_bound(snap_id);
            return it->second;
        }
        return sa[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */