class TrieNode {
public:
    TrieNode *children[26];
    bool end;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        end = false;
    }
};

class Solution {
private:
    void addWord(string word, TrieNode *root){
        TrieNode *curr = root;
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr){
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->end = true;
    }

    string currWord;
    unordered_set<string> res;
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>> &visited, TrieNode *curr){
        int m = board.size(), n = board[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || (curr->children[board[i][j] - 'a'] == nullptr)){
            return;
        }
        visited[i][j] = true;
        int idx = board[i][j] - 'a';
        currWord.push_back(board[i][j]);
        curr = curr->children[idx];
        if(curr->end){
            res.insert(currWord);
        }

        dfs(board, i+1, j, visited, curr);
        dfs(board, i-1, j, visited, curr);
        dfs(board, i, j+1, visited, curr);
        dfs(board, i, j-1, visited, curr);

        currWord.pop_back();
        visited[i][j] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();

        for(string word : words){
            addWord(word, root);
        }

        currWord = "";
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, i, j, visited, root);
            }
        }
        vector<string> ans;
        for(auto it : res){
            ans.push_back(it);
        }
        return ans;
    }
};