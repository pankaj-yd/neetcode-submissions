class Solution {
private:
    void dfs(unordered_map<string, set<string>> &g, unordered_map<string, int> &f, string u, vector<string> &ans, int &total){
        // go to those places from where we can come back
        ans.push_back(u);
        if(total == 0){
            return;
        }
        
        for(string v : g[u]){
            string key = u + "-" + v;
            if(f[key] > 0){
                f[key]--;
                total--;
                dfs(g, f, v, ans, total);
                if(total == 0){
                    return;
                }
                f[key]++;
                total++;
            }
        }

        ans.pop_back();
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, set<string>> g;
        unordered_map<string, int> f;

        for(vector<string> ticket : tickets){
            g[ticket[0]].insert(ticket[1]);
            f[(ticket[0] + "-" + ticket[1])]++;
        }
        vector<string> ans;
        int total = tickets.size();
        dfs(g, f, "JFK", ans, total);

        return ans;

    }
};
