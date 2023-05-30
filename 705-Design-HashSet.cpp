class MyHashSet {
public:
    int arr[10000001];   //size of array
    
    MyHashSet() {
        memset(arr,-1,sizeof(arr));       //insert into the array
    }
    
    void add(int key) {
        arr[key]=1;
    }
    
    void remove(int key) {
        arr[key]=-1;
    }
    
    bool contains(int key) {
        return arr[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
