class Solution {
private:
    bool dfs(vector<vector<int>> &g, int i, unordered_set<int> &visited, unordered_set<int> &currdfs, vector<int> &ans){
        if(currdfs.find(i) != currdfs.end()){
            return false;
        }
        if(visited.find(i) != visited.end()){
            return true;
        }

        currdfs.insert(i);
        visited.insert(i);
        for(int neigh : g[i]){
            if(!dfs(g, neigh, visited, currdfs, ans)){
                return false;
            }
        }

        currdfs.erase(i);
        ans.push_back(i);
        return true;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        for(vector<int> v : prerequisites){
            g[v[0]].push_back(v[1]);

        }

        unordered_set<int> visited;
        unordered_set<int> currdfs;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!dfs(g, i, visited, currdfs, ans)){
                return {};
            }
        }

        return ans;

    }
};
