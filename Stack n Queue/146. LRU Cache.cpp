class LRUCache {
    
public:
    class node{
        public :
        int key;
        int val;

        node* pre;
        node* next;

        node(int k,int v){
            this -> key = k;
            this -> val = v;
        }
    };

    unordered_map<int,node*> mp;
    int cap;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    void addnode(node* newnode){
         node* temp = tail->pre;

         newnode -> next = tail;
         newnode -> pre = temp;

         temp->next = newnode;
         tail->pre = newnode;
    }

    void delnode(node* del){
        node* nnxt = del->next;
        node* ppre = del->pre;

        ppre->next = nnxt;
        nnxt->pre = ppre;
    }


    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        node* n = mp[key];
        int ans = n->val;
        
        mp.erase(key);

        delnode(n);
        addnode(n);

        mp[key] = tail->pre;
        return ans;
    }
    
    void put(int key, int value) {
        node* newone = new node(key,value);
        if(mp.find(key) != mp.end()){
            node* n = mp[key];
            
            mp.erase(key);
            delnode(n);
        }
        
        if(mp.size() == cap){
                mp.erase(head->next->key);
                delnode(head->next);
        }

        addnode(newone);
        mp[key] = tail->pre;
                
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */