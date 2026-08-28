class Solution {
private:
    bool check(string &s, int i, int op, unordered_map<long, bool> &umap){
        if(i >= s.size() && op == 0) return true;
        if(i >= s.size() || op < 0) return false;

        long key = ((long)i)<< 32 | long(op);
        if(umap.find(key) != umap.end()){
            return umap[key];
        }
        if(s[i] == '(') {
            umap[key] = check(s, i+1, op+1, umap);
        }
        else if(s[i] == ')'){
            umap[key] =  check(s, i+1, op-1, umap);
        }else {
            bool open =  check(s, i+1, op+1, umap);

            bool close =  check(s, i+1, op-1, umap);

            bool ignore = check(s, i+1, op, umap);

            umap[key] =  open || close || ignore;
        }
        return umap[key];
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        unordered_map<long, bool> umap;
        return check(s, 0, 0, umap);
    }
};
