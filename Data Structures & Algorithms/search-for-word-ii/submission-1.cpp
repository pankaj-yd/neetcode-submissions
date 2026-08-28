class TrieNode {
public:
    TrieNode *children[26];
    bool word;
    int count;
    TrieNode(){
        for(int i= 0; i < 26; i++){
            children[i] = nullptr;
        }
        word = false;
        count = 0;
    }
};

class Trie {
public:
    TrieNode *root;

    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';

            if(node->children[idx] == nullptr){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->word = true;
        node->count += 1;
    }

};

class Solution {
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode *root, string &curr, vector<string> &res){
        if(root->word && root->count && curr.size() > 0){
            root->count--;
            res.push_back(curr);
        }

        if(i >= board.size() || i < 0 
        || j >= board[0].size() || j < 0 || board[i][j] == '.' ||
        root == nullptr || root->children[board[i][j] - 'a'] == nullptr){
            return;
        }

        // if(root->word){
        //     res.push_back(curr);
        // }
        int idx = board[i][j] - 'a';
        cout << i << " " << j << " " << board[i][j] << endl;
        curr.push_back(board[i][j]);
        board[i][j] = '.';
        dfs(board, i+1, j, root->children[idx], curr, res);
        dfs(board, i-1, j, root->children[idx], curr, res);
        dfs(board, i, j+1, root->children[idx], curr, res);
        dfs(board, i, j-1, root->children[idx], curr, res);
        curr.pop_back();
        board[i][j] = 'a' + idx;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = new Trie();
        
        for(string word: words){
            trie->insert(word);
        }

        vector<string> res;
        string curr;
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                dfs(board, i, j, trie->root, curr, res);
            }
        }
        
        return res;
    }
};
