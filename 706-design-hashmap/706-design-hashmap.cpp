class MyHashMap {
public:

    int* hash;
    MyHashMap() {
        
        hash = new int[1000001];
        // initializing all entries in the hashtable with -1 so that -1 will be returned for misses
		for(int i=0;i<1000001;i++) {
            hash[i] = -1;
        }
    }

    void put(int key, int value) {
        hash[key] = value;
    }

    int get(int key) {
        return hash[key];
    }

    void remove(int key) {
	//setting the entry back to -1 so that for the subsequent get calls for this key -1 will be returned
        hash[key] = -1;
    }
};