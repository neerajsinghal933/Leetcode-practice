class RandomizedSet {
public:
    unordered_set<int>st;
    RandomizedSet() {
        st.clear();
    }
    
    bool insert(int val) {
        bool flag = false;
        if(st.find(val)==st.end())
            flag = true;
        st.insert(val);
        return flag;
    }
    
    bool remove(int val) {
        bool flag = false;
        auto it = st.find(val);
        if(it!=st.end())
            flag = true;
        if(flag)
            st.erase(it);
        // st.insert(val);
        return flag;
    }
    
    int getRandom() {
        int n = st.size();
        int t = rand()%n;
        auto it = st.begin();
        while(t--)
            it++;
        // std::advance(it, t);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */