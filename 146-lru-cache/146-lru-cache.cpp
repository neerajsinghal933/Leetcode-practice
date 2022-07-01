class LRUCache {
public:
    struct node{
        int key;
        int val;
        node* left;
        node* right;
        
        node(int key, int val)
        {
            this->key = key;
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };
    
    unordered_map<int, node*>m;
    int cap, size;
    node* head, *tail;
    
    void deleteNode(node* t)
    {
        if(t->left!=NULL)
        {
            t->left->right = t->right;
        }
        else
            head = t->right;
        if(t->right)
            t->right->left = t->left;
        else
            tail = t->left;
        t->left = NULL;
        t->right = NULL;
        size--;
    }
    
    void insertNode(node* t)
    {
        size++;
        if(!head)
        {
            head = tail = t;
            return;
        }
        tail->right = t;
        t->left = tail;
        tail = t;
        return;
    }
    
    
    
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        node* p = m[key];
        deleteNode(p);
        insertNode(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node* p = m[key];
            deleteNode(p);
            p->val = value;
            m[key] = p;
            insertNode(p);
        }
        else
        {
            node* p = new node(key, value);
            m[key] = p;
            if(size<cap)
            {
                insertNode(p);
                return;
            }
            m.erase(head->key);
            deleteNode(head);
            insertNode(p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */