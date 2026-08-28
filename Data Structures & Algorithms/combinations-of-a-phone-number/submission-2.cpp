class Solution {
private:
    void letterComb(string &d, unordered_map<char, string> &umap, int i, vector<string> &res, string &curr){
        cout << "i: " << i << endl;
        cout << curr << endl;
        if(i == d.size()){
            res.push_back(curr);
            return;
        }
        string chars = umap[d[i]];
        cout << "chars: " << chars << endl;
        for(char c : chars){
            curr.push_back(c);
            letterComb(d, umap, i+1, res, curr);
            curr.pop_back();
        }
    } 
public:
    vector<string> letterCombinations(string d) {
        if(d.size() == 0){
            return {};
        }
        unordered_map<char, string> umap;
        umap.insert({'2', "abc"});
        umap.insert({'3', "def"});
        umap.insert({'4', "ghi"});
        umap.insert({'5', "jkl"});
        umap.insert({'6', "mno"});
        umap.insert({'7', "pqrs"});
        umap.insert({'8', "tuv"});
        umap.insert({'9', "wxyz"});

        vector<string> res;
        string curr;
        letterComb(d, umap, 0, res, curr);
        return res;
    }
};
