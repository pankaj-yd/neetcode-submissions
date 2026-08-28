class Solution {
private:
    void dfs(vector<vector<int>> &g, vector<bool> &visited, int i, int p){
        if(visited[i]){
            return;
        }
        visited[i] = true;
        for(int j : g[i]){
            if(j != p){
                dfs(g, visited, j, i);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>());

        for(vector<int> e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(g, visited, i, -1);
                count++;
            }
        }

        return count;

    }
};
