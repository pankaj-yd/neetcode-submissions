class LRUCache {
private:
    unordered_map<int, int> umap;
    unordered_map<int, int> lru;
    int total = 0;
    int counter = 0;
public:

    LRUCache(int capacity) {
        total = capacity;
    }
    
    int get(int key) {
        if(umap.find(key) == umap.end()) {
            return -1;
        }
        lru[key] = counter++;
        return umap[key];
    }
    
    void put(int key, int value) {
        if(umap.find(key) == umap.end()) {
            if(umap.size() >= total){
                // get lru
                int minVal = 1001;
                int minKey = -1;
                // erase lru
                for(auto it : lru){
                    if(minVal > it.second){
                        minVal = it.second;
                        minKey = it.first;
                    }
                }
                umap.erase(minKey);
                lru.erase(minKey);
            }
            umap.insert({key, value});
            lru.insert({key, counter++});
        } else {
            umap[key] = value;
            lru[key] = counter++;
        }
    }
};
