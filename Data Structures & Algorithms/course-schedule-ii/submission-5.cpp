class Solution {
private:
    bool dfs(vector<vector<int>> &g, vector<int> &visited, int u, vector<int> &ans){
        if(visited[u] == 1){
            return true;
        }

        visited[u] = 1;

        for(int v : g[u]){
            if(visited[v] != 2){
                if(dfs(g, visited, v, ans)){
                    return true;
                }
            }
        }

        visited[u] = 2;
        ans.push_back(u);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n, vector<int>());

        for(vector<int> prereq : prerequisites){
            g[prereq[0]].push_back(prereq[1]);
        }

        vector<int> visited(n, -1);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(visited[i] == -1){
                if(dfs(g, visited, i, ans)){
                    return {};
                }
            }
        }

        return ans;
    }
};
