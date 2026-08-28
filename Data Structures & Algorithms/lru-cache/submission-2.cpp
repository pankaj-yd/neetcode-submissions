class Node {
public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node (int k, int v){
        key = k;
        val = v;
    }
};

class LRUCache {
private:
    int total;
    unordered_map<int, Node *> cache;
    Node *left = nullptr;
    Node *right = nullptr;
public:
    LRUCache(int capacity) {
        total = capacity;
        left = new Node(-1, -1);
        right = new Node(1001, 1001);
        
        left->prev = nullptr;
        left->next = right;

        right->prev = left;
        right->next = nullptr;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }

        // exists in cache
            Node *ptr = cache[key];

        // move to beginning of linked list
        if(ptr->next->val != right->val){
            // link left and right of ptr
            Node *leftOfPtr = ptr->prev;
            Node *rightOfPtr = ptr->next;

            leftOfPtr->next = rightOfPtr;
            rightOfPtr->prev = leftOfPtr;

            // move ptr to right
            Node *lru = right->prev;
            lru->next = ptr;
            ptr->prev = lru;

            ptr->next = right;
            right->prev = ptr;
        }
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            // does not exist in cache
            if(cache.size() >= total){
                Node *lru = left->next;
                cache.erase(lru->key);


                left->next = lru->next;
                lru->next->prev = left;


                delete lru;
            }

            Node *newNode = new Node(key, value);
            cache.insert({key, newNode});
            
            Node *mru = right->prev;

            mru->next = newNode;
            newNode->prev = mru;

            newNode->next = right;
            right->prev = newNode;
        } else {
            // exists in cache
            Node *ptr = cache[key];

            // update the value
            ptr->val = value;

            // move to beginning of linked list
            if(ptr->next->val != right->val){
                // link left and right of ptr
                Node *leftOfPtr = ptr->prev;
                Node *rightOfPtr = ptr->next;

                leftOfPtr->next = rightOfPtr;
                rightOfPtr->prev = leftOfPtr;

                // move ptr to right
                Node *lru = right->prev;
                lru->next = ptr;
                ptr->prev = lru;

                ptr->next = right;
                right->prev = ptr;
            }
        }
    }
};
