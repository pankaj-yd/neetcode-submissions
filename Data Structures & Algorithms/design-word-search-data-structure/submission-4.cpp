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

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for(char c : word){
            int idx = c - 'a';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        return deepSearch(word, 0, root);
    }

    bool deepSearch(string &word, int i, TrieNode *curr){
        if(i >= word.size() && curr != nullptr){
            return curr->end;
        }
        if(curr == nullptr){
            return false;
        }

        if(word[i] == '.'){
            for(int j = 0; j < 26; j++){
                if(deepSearch(word, i+1, curr->children[j])){
                    return true;
                }
            }
        } else {
            return deepSearch(word, i+1, curr->children[word[i] - 'a']);
        }
        return false;
    }

};
