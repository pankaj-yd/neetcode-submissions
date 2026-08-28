class Solution {
private:
    bool checkOverlap(string &s, string &word, int start){
        
        int n1 = s.size() - start, n2 = word.size();

        if(n1 < n2){return false;}

        int i = 0;
        while(i < n2){
            if(s[i + start] != word[i]) return false;
            i++;
        }
        return true;
    }

    bool exists(string &s, unordered_map<int, bool> &umap, vector<string>& wordDict, int start){
        if(umap.find(start) != umap.end()){
            return umap[start];
        } else if(start == s.size()){
            return true;
        }

        cout << start << endl;
        int n = s.size() - start;

        for(string &word : wordDict){
            if(checkOverlap(s, word, start)){
                cout << "overlapped: " << word << endl;
                int n2 = word.size();
                if (exists(s, umap, wordDict, start + n2)){
                    umap.insert({start, true});
                    return true;
                }
            }
        }
        
        umap.insert({start, false});
        return false;

    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> umap;

        return exists(s, umap, wordDict, 0);

    }
};
