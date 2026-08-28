class PrefixTreeNode {  
public:
    PrefixTreeNode* chars[26];
    bool wordEnd = false;
    PrefixTreeNode(){
        for(int i = 0; i < 26; i++){
            chars[i] == nullptr;
        }
    }
};

class PrefixTree {
private:
    PrefixTreeNode *head;
public:
    PrefixTree() {
        head = new PrefixTreeNode();
    }
    
    void insert(string word) {
        PrefixTreeNode *curr = head;
        int n = word.size();
        int i = 0;
        while(i < n){
            if(curr->chars[word[i] - 'a'] == nullptr){
                PrefixTreeNode *newNode = new PrefixTreeNode();
                curr->chars[word[i] - 'a'] = newNode;
            }
            if(i == n-1){
                curr->chars[word[i] - 'a']->wordEnd = true;
            }
            curr = curr->chars[word[i] - 'a'];
            i++;
        }
    }
    
    bool search(string word) {
        if(word.size() == 0){
            return true;
        }

        PrefixTreeNode *curr = head;
        for(char c : word){
            curr = curr->chars[c - 'a'];
            if( !curr){
                return false;
            }
        }
        return curr->wordEnd;

    }
    
    bool startsWith(string prefix) {
        if(prefix.size() == 0){
            return true;
        }
        PrefixTreeNode *curr = head;
        for(char c : prefix){
            curr = curr->chars[c - 'a'];
            if( !curr){
                return false;
            }
            
        }
        return true;
    }
};
