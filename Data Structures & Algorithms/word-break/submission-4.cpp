class TrieNode {
public:
    TrieNode *childrens[26];
    bool wordEnd;

    TrieNode(){
        for (int i = 0; i < 26; i++){
            childrens[i] = nullptr;
        }
        wordEnd = false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    void addWord(string& word){
        TrieNode *curr = root;
        for(char ch : word){
            int chVal = ch - 'a';
            if (curr->childrens[chVal] == nullptr){
                curr->childrens[chVal] = new TrieNode();
            }
            curr = curr->childrens[chVal];
        }
        curr->wordEnd = true;
    }

    bool searchWord(string& word, int i, int j){
        TrieNode *curr = root;
        for (int k = i; k <= j; k++){
            int chVal = word[k] - 'a';
            if (curr->childrens[chVal] == nullptr){
                return false;
            }
            curr = curr->childrens[chVal];
        }
        return curr->wordEnd;
    }

    void printTrie(){
        queue<TrieNode*> q;
        
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TrieNode* node = q.front();
                q.pop();

                for (int j = 0; j < 26; j++){
                    if (node->childrens[j] != nullptr){
                        cout << char(j + 'a')<< node->childrens[j]->wordEnd << " ";
                        q.push(node->childrens[j]);
                    }
                }
                cout << "|";
            }
            cout << endl;
        }
    }

    TrieNode* getRoot(){
        return root;
    }
};

class Solution {
    TrieNode* root;
    
public:
    bool wordBreak(string s, vector<string>& wordDict){
        Trie trie;
        for (string& s : wordDict){
            trie.addWord(s);
        }
        
        int maxLen = 0;
        for(string w : wordDict){
            maxLen = max(maxLen, (int)w.size());
        }

        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < min(n, i+maxLen); j++){
                if (trie.searchWord(s, i, j)){
                    dp[i] = dp[j+ 1];
                }
                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};

// neet, neta
//
