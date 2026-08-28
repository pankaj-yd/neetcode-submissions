class Solution {
private:
    void dfs(vector<vector<int>> &g, int i, vector<bool> &visited, int &count){

        if(visited[i]){
            return;
        }
        
        visited[i] = true;
        count++;
        for(int j : g[i]){
            dfs(g, j, visited, count);
        }
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

        dfs(graph, 0, visited, count);
        cout << count << endl;
        return count == n;
    }
};
