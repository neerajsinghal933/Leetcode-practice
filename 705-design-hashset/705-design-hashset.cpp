class MyHashSet {
public:
    // map<int, int>m;
    int hash[1000001];
    MyHashSet() {
        memset(hash, 0, sizeof(hash));
    }
    
    void add(int key) {
        // m[key] = 1;
        hash[key]=1;
    }
    
    void remove(int key) {
        // m[key] = 0;
        hash[key] = 0;
    }
    
    bool contains(int key) {
        // if(m[key]==0)
        //     return false;
        // return true;
        if(hash[key]==0)
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */