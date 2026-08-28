class Solution {
private:
    bool dfs(unordered_map<string, set<string>> &g, string source, 
    unordered_map<string, int> &counter, vector<string> &ans, int &total){
        ans.push_back(source);

        for(string dest : g[source]){
            string stod = source + dest;
            if(counter[stod] > 0){
                counter[stod]--;
                total--;
                bool allUsed = dfs(g, dest, counter, ans, total);
                if(!allUsed){
                    counter[stod]++;
                    total++;
                }
            }
        }

        if(total == 0){
            return true;
        }
        ans.pop_back();
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, set<string>> graph;
        unordered_map<string, int> counter;

        for(vector<string> ticket : tickets){
            graph[ticket[0]].insert(ticket[1]);
            string stod = ticket[0] + ticket[1];
            if(counter.find(stod) == counter.end()){
                counter.insert({stod, 1});
            } else {
                counter[stod]++;
            }
        }

        vector<string> ans;
        int total = tickets.size();
        dfs(graph, "JFK", counter, ans, total);
        return ans;
        
    }
};
