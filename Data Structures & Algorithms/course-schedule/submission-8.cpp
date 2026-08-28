class Solution {
private:
    bool dfs(vector<vector<int>> &g, int &time, vector<int> &start, vector<int> &end, int u){
        cout << u << endl;
        if(start[u] != -1 && end[u] == -1) {
            return true;
        }

        start[u] = time++;
        bool hasCycle = false;
        for(int v : g[u]){
            if(end[v] == -1){
                if(dfs(g, time, start, end, v)){
                    hasCycle = true;
                    break;
                }
            }
        }

        end[u] = time++;
        return hasCycle;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() > n){
            return false;
        }

        vector<vector<int>> g(n, vector<int>());
        for(vector<int> preReq : prerequisites){
            g[preReq[0]].push_back(preReq[1]);
        }


        vector<int> start(n, -1);
        vector<int> end(n, -1);
        int time = 0;
        for(int i = 0; i < n; i++){
            if(start[i] == -1 && end[i] == -1){
                if(dfs(g, time, start, end, i)){
                    cout << "cycle found in dfs i: " << i << endl;
                    return false;
                }
            }
        }

        return true;
        
    }
};

