class Solution {
private:
    bool checkDiff(string s, string t){
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){count++;}
            if(count > 1){
                return false;
            }
        }
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if(words.find(endWord) == words.end()){
            return 0;
        }

        queue<string> q;
        int lvl = 0;
        q.push(beginWord);
        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i++){
                string curr = q.front();
                q.pop();
                if(curr == endWord){
                    return lvl;
                }
                // find neighbors of curr
                vector<string> toErase;
                for(string word : words){
                    if(checkDiff(curr, word)){
                        if(word == endWord){
                            return lvl + 2;
                        }
                        q.push(word);
                        toErase.push_back(word);

                    }
                }
                for(string word : toErase){
                    words.erase(word);
                }
            }
            lvl++;
        }

        return 0;
    }
};
