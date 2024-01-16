class RandomizedSet {
public:
    // Using Map
    unordered_map <int,int> mp ;
    vector <int> v ;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)){
            
            return false;
        }
        v.push_back(val) ;
        mp[val]  = v.size() -1 ; // storing index 
        return true ;
    
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            int index = mp[val] ; // getting val index from map
            int l_value = v.back() ; // last value in vector
            v[index] = l_value ; // shifting last value to new index
            v.pop_back() ;
            mp[l_value] = index;
            mp.erase(val);
            return true ;
        }
        return false ;
    }
    
    int getRandom() {
        //int ind = rand()% v.size() ;
        int ind = rand() % (v.size());
        return v[ind] ;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
