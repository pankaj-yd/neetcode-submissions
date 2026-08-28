class Solution {
private:
    bool dfs(unordered_map<char, unordered_set<char>> &g, char u, unordered_map<char, bool> &visited, string &ans){
        if(visited.find(u) != visited.end()){
            return visited[u];
        }

        visited[u] = true;
        for(char v : g[u]){
            if(dfs(g, v, visited, ans)){
                return true;
            }
        }
        visited[u] = false;
        ans.push_back(u);

        return false;
    }

public:
    string foreignDictionary(vector<string>& words){
        if(words.size() == 1){
            return words[0];
        }
        unordered_map<char, unordered_set<char>> g;

        for(int i = 1; i < words.size(); i++){
            string s = words[i-1];
            string t = words[i];

            int j = 0;
            while(j < s.size() && j < t.size() && s[j] == t[j]){
                j++;
            }
            if(j < s.size()){
                if(j == t.size()){
                    return "";
                }
                g[s[j]].insert(t[j]);
            }

            for(char c : s){
                if(g.find(c) == g.end()){
                    g[c] = unordered_set<char>();
                }
            }
            for(char c : t){
                if(g.find(c) == g.end()){
                    g[c] = unordered_set<char>();
                }
            }
        }

        unordered_map<char, bool> visited;
        string ans;
        for(auto it : g){
            if(dfs(g, it.first, visited, ans)){
                return "";
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};