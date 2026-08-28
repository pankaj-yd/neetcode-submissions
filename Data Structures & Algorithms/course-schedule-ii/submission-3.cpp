class Solution {
private:
    bool dfs(
        vector<vector<int>> &g, int i, vector<int> &ans, 
        vector<int> &start, vector<int> &end, int &count){
        cout << i << " ";
        cout << start[i] << " " << end[i] << endl;
        if(end[i] == -1 && start[i] != -1){
            ans.clear();
            cout << "returning false" << endl;
            return false;
        } else if (start[i] != -1 && end[i] != -1){
            return true;
        }
        start[i] = count++;
        for(int v : g[i]){
            if (!dfs(g, v, ans, start, end, count)){
                return false;
            }
        }
        end[i] = count++;
        ans.push_back(i);
        return true;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<bool> source(n, true);
        for(vector<int> v : prerequisites){
            g[v[0]].push_back(v[1]);
            source[v[1]] = false;
        }

        vector<int> ans;
        vector<int> startTime(n, -1), endTime(n, -1);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(source[i]){
                bool isPossible = dfs(g, i, ans, startTime, endTime, count);
                if(!isPossible){
                    return {};
                }
            }
        }
        return ans;

    }
};
