class MyHashSet {
public:
    
    int sz=1000001;
    vector<int> vect;
    MyHashSet() {
        vect.resize(sz);
    }
    
    void add(int key) {
        vect[key] = 1;
    }
    
    void remove(int key) {
        vect[key] = 0;
    }
    
    bool contains(int key) {
        return vect[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */