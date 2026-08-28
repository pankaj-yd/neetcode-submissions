class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0);
        vector<int> rank(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        int count = n;
        for(vector<int> e : edges){
            int u = e[0], v = e[1];
            int pu = parent[u], pv = parent[v];
            while(pu != parent[pu]){
                pu = parent[pu];
            }
            while(pv != parent[pv]){
                pv = parent[pv];
            }
            if(pu != pv){
                if(rank[pu] < rank[pv]){
                    parent[pu] = pv;
                    rank[pv] += rank[pu];
                } else {
                    parent[pv] = pu;
                    rank[pu] += rank[pv];
                }
                count--;
            }
        }
        return count;
    }
};
