class SmallestInfiniteSet {
public:
    set<int>used;
    int smallest = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int res = smallest;
        used.insert(smallest);
        while(used.find(smallest)!= end(used))
            smallest++;
        return res;
    }
    
    void addBack(int num) {
        if(used.find(num) != end(used))
            used.erase(num);
        if(smallest > num)
            smallest = num;
    }
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
