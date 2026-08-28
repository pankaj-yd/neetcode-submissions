class Solution {
private:
    void dfs(unordered_map<string, queue<string>> &g, string u, vector<string> &ans){
        while(!g[u].empty()){
            string v = g[u].front();
            g[u].pop();
            dfs(g, v, ans);
        }

        ans.push_back(u);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());

        unordered_map<string, queue<string>> g;
        for(vector<string> ticket : tickets){
            g[ticket[0]].push(ticket[1]);
        }

        vector<string> ans;

        dfs(g, "JFK", ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
