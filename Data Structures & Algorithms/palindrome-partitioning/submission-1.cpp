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

    void part(vector<vector<string>> &res, string &s, int start, int end, vector<string> curr){
        if( start == end && (start >= s.size() || end >= s.size()) ){
            res.push_back(curr);
            return;
        } else if((start >= s.size() || end >= s.size())){
            return;
        }

        
        bool ispalindrome = isPali(s, start, end);
        if(ispalindrome) {
            // split substring 
            curr.push_back(s.substr(start, end - start + 1));
            part(res, s, end + 1, end + 1, curr);
            curr.pop_back();
        }
        
        part(res, s, start, end + 1, curr);
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        part(res, s, 0, 0, {});
       
        return res;
    }
};
