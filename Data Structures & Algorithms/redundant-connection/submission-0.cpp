class Solution {
private:
    int dofind(vector<int> &p, int i){
        while(i != p[i]){
            p[i] = p[p[i]];
            i = p[i];
        }
        return i;
    }
    
    int dounion(vector<int> &p,vector<int> rank, int i, int j){
        int pi = dofind(p, i), pj = dofind(p, j);

        if(pi == pj) {
            return 0;
        } else if( rank[pi] < rank[pj]){
            p[pi] = pj;
            rank[pj] += rank[pi];
        } else {
            p[pj] = pi;
            rank[pi] += rank[pj];
        }
        return 1;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n + 1, 0), rank(n + 1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }

        for(vector<int> e : edges){
            int res = dounion(parent, rank, e[0], e[1]);
            if(res == 0){
                return e;
            }
        }
        return {-1, -1};
    }
};
