class Solution {
private:
    bool dfs(unordered_map<char, vector<char>> &graph, char c, string &ans, 
    vector<bool> &chars, unordered_set<char> &visited){
        if(visited.find(c) != visited.end()){
            return true;
        }
        if(chars[c - 'a']){
            return false;
        }
        if(graph.find(c) == graph.end()){
            return true;
        }
        chars[c - 'a'] = true;
        cout << "graphing: " << c << endl;
        for(char v : graph[c]){
            if ( !dfs(graph, v, ans, chars, visited) ){
                return false;
            }
        }
        ans.push_back(c);
        graph[c].clear();
        chars[c - 'a'] = false;
        visited.insert(c);
        return true;
    }

public:
    string foreignDictionary(vector<string>& words) {
        if(words.size() == 1){
            return words[0];
        }
        unordered_map<char, vector<char>> graph;
        int n = words.size();
        int i = 1;
        while(i < n){
            int n1 = words[i-1].size();
            int n2 = words[i].size();
            int j = min(n1, n2);
            int k = 0;
            string s1 = words[i-1], s2 = words[i];
            bool diffLetter = false;
            while(k < j){
                if(s1[k] != s2[k]){
                    graph[s1[k]].push_back(s2[k]);
                    diffLetter = true;
                    break;
                }
                k++;
            }
            if(!diffLetter && n1 > n2){
                return "";
            }
            i++;
            for(char c : s1){
                if(graph.find(c) == graph.end()){
                    graph[c] = {};
                }
            }
            for(char c : s2){
                if(graph.find(c) == graph.end()){
                    graph[c] = {};
                }
            }
        }
        
        vector<bool> chars(26, false);
        unordered_set<char> visited;
        string ans;
        for(int i = 0; i < 26; i++){
            if (visited.find(i) == visited.end()){
                if(!dfs(graph, i + 'a', ans, chars, visited)){
                    cout << i << endl;
                    return "";
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};