class Solution {
private:
    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int i){
        if(visited[i]){
            return false;
        }

        visited[i] = true;
        for(int neigh : graph[i]){
            if ( !dfs(graph, visited, neigh) ){
                return false;
            }
        }
        visited[i] = false;
        graph[i].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());

        for(vector<int> v : prerequisites){
            graph[v[0]].push_back(v[1]);
        }

        vector<bool> visited(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if ( !dfs(graph, visited, i) ){
                return false;
            }
        }
        return true;

    }
};

