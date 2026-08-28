class Solution {
private:
    bool checkOverlap(string s, string word){
        int n1 = s.size(), n2 = word.size();

        if(n1 < n2){return false;}

        int i = 0;
        while(i < n2){
            if(s[i] != word[i]) return false;
            i++;
        }
        return true;
    }

    bool exists(string s, unordered_map<string, bool> &umap, vector<string>& wordDict){
        if(umap.find(s) != umap.end()){
            return umap[s];
        }

        int n = s.size();
        for(int i = 0; i < s.size(); i++){
            for(string word : wordDict){
                if(checkOverlap(s, word)){
                    int n2 = word.size();
                    if (exists(s.substr(n2, n - n2), umap, wordDict)){
                        umap.insert({s, true});
                        return true;
                    }
                }
            }
        }
        umap.insert({s, false});
        return false;

    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> umap;
        for(string word : wordDict){
            umap.insert({word, true});
        }

        return exists(s, umap, wordDict);

    }
};
