class Solution {
private:
    bool hasCycle(vector<vector<int>> &g, vector<bool> &visited, int i, int p){
        if(visited[i]){
            return true;
        }
        
        visited[i] = true;
        
        for(int j : g[i]){
            if(j != p && hasCycle(g, visited, j, i)){
                return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }
        
        vector<vector<int>> graph(n, vector<int>());
        for(vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        vector<bool> visited(n, false);

        bool cycle = hasCycle(graph, visited, 0, -1);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                return false;
            }
        }
        return !cycle;
    }
};
