class TimeMap {
public:
    unordered_map< string, vector<pair<int, string>> > umap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if( umap.find(key) == umap.end() ){
            umap.insert({key, { {timestamp, value} } });
        } else {
            umap[key].push_back({timestamp, value});
        }
    }
    
    string get(string key, int timestamp) {
        if( umap.find(key) == umap.end()) {
            return "";
        }

        vector<pair<int, string>> v = umap[key];
        int n = v.size();

        string ans = "";
        for(int i = n-1; i >= 0; i--){
            if (v[i].first <= timestamp){
                ans = v[i].second;
                break;
            }
        }
        return ans;
    }
};
