class Solution {
    bool dfs(unordered_map<char, unordered_set<char> > &g, string &ans, char u, vector<int> &visited){
        if(visited[u - 'a'] == 1){
            return true;
        }

        visited[u - 'a'] = 1;
        for(char v : g[u]){
            if(visited[v - 'a'] != 2){
                if(dfs(g, ans, v, visited)){
                    return true;
                }
            }
        }
        ans.push_back(u);
        visited[u - 'a'] = 2;

        return false;
    }

public:
    string foreignDictionary(vector<string>& words){
        if(words.size() == 1){
            return words[0];
        }
        unordered_map<char, unordered_set<char> > g;

        int n = words.size();
        for(int i = 1; i < n; i++){
            int j = 0;
            string s = words[i-1];
            string t = words[i];

            while(j < s.size() && j < t.size() && s[j] == t[j]){
                j++;
            }

            if(s.size() > t.size() && j == t.size()){
                return "";
            }

            g[s[j]].insert(t[j]);
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

        string ans = "";
        vector<int> visited(26, -1);
        for(auto it : g){
            if(visited[it.first - 'a'] == -1){
                if(dfs(g, ans, it.first, visited)){
                    return "";
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};