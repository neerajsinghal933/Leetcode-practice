class MyHashSet {
public:
    vector<int> vect;
    int size;
    MyHashSet() {
        size = 1e6+1;
        vect.resize(size);
        
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