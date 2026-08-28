class Solution {
private:
    bool isPali(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void part(vector<vector<string>> &res, string &s, int start, vector<string> &curr){
        if(start == s.size()){
            res.push_back(curr);
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(isPali(s, start, i)){
                curr.push_back(s.substr(start, i - start + 1));
                part(res, s, i+1, curr);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        part(res, s, 0, curr);
       
        return res;

    }
};
