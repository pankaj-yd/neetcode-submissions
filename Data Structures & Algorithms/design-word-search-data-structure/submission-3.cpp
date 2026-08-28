class WordDictionaryNode {
public:
    WordDictionaryNode *children[26];
    bool isWord;

    WordDictionaryNode(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class WordDictionary {
private:
    WordDictionaryNode *root;
public:
    WordDictionary() {
        root = new WordDictionaryNode();
    }
    
    void addWord(string word) {
        WordDictionaryNode *node = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(node->children[idx] == nullptr){
                node->children[idx] = new WordDictionaryNode();
            }
            node = node->children[idx];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        bool ans = false;
        search2(word, 0, root, ans);

        return ans;
        
    }

    void search2(string &word, int i, WordDictionaryNode *node, bool &ans){
        if(ans){
            return;
        } else if(i < word.size() && node == nullptr){
            cout << "i less than word size and node is NULL" << endl;
            return;
        } else if(i == word.size() && node != nullptr){
            ans = node->isWord;
            return;
        } else if (i == word.size()){
            return;
        }

        cout << "word[i]: " << word[i] << endl;
        if(word[i] != '.'){
            cout << "child of: " << word[i] << endl;
            search2(word, i+1, node->children[word[i] - 'a'], ans);
        } else {
            if(node == nullptr){
                return;
            }
            for(int k = 0; k < 26; k++){
                cout << "child of: " << char(k + 'a') << endl;
                search2(word, i+1, node->children[k], ans);
            }
        }
    }
};
