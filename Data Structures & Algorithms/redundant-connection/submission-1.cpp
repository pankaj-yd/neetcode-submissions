class Solution {
private:
    vector<int> p, r;
    void Union(int u, int v){
        int pu = Find(u);
        int pv = Find(v);

        if(r[pu] < r[pv]){
            p[pu] = pv;
        } else if(r[pu] > r[pv]){
            p[pv] = pu;
        } else {
            p[pu] = pv;
            r[pv]++;
        }
    }

    int Find(int u){
        if(p[u] == u){
            return u;
        }
        return p[u] = Find(p[u]);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        p.resize(n+1);
        r.resize(n+1, 0);
        for(int i = 0; i <= n; i++){
            p[i] = i;
        }

        for(vector<int> e : edges){
            int u = e[0], v = e[1];
            int pu = Find(u), pv = Find(v);
            if(pu != pv){
                Union(u, v);
            } else {
                return e;
            }
        }

        return {};
    }
};
