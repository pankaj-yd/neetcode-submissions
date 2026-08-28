class Solution {
private:
    bool dfs(string &s, string &t, string &u, int i, int j, int k, unordered_map<string, bool> umap){
        if(k == u.size()) {
            return true;
        }
        int p = s.size(), q = t.size(), r = u.size();

        string key = to_string(i) + "-" + to_string(j) + "-" + to_string(k);
        if(umap.find(key) != umap.end()){
            return umap[key];
        }

        for(int l = i; l < p; l++){
            if(s[l] == u[k]){
                if(dfs(s, t, u, i+1, j, k+1, umap)) {
                    umap[key] = true;
                    return true;
                }
            }
        }

        for(int l = j; l < q; l++){
            if(t[l] == u[k]){
                if(dfs(s, t, u, i, j+1, k+1, umap)) {
                    umap[key] = true;
                    return true;
                }
            }
        }

        umap[key] = false;
        return false;
    }
public:
    bool isInterleave(string s, string t, string u) {
        int p = s.size(), q = t.size(), r = u.size();
        if(p + q != r) return false;
        unordered_map<string, bool> umap;
        return dfs(s, t, u, 0, 0, 0, umap);
    }
};
