class Solution {
private:
    bool check(string &s, string &p, int i, int j, unordered_map<string, bool> &memo){
        // cout << i << "," << j << "  ->  " ;
        if(j == p.size() && i == s.size()) return true;
        if(j == p.size()) return false;

        
        string key = to_string(i) + "-" + to_string(j);

        if(memo.find(key) != memo.end()){
            return memo[key];
        }

        
        bool path1 = false;
        if(j < p.size() - 1 && p[j+1] == '*'){
            // match from 0 times to multiple times
            for(int k = i; k < s.size(); k++){
                // if matching
                if( (p[j] == '.' || p[j] == s[k] ) ){
                    if(check(s, p, k+1, j+2, memo)){
                        memo[key] = true;
                        return true;
                    }
                } else {
                    break;
                }
            }

            // ignore the character
            if(check(s, p, i, j+2, memo)){
                memo[key] = true;
                return true;
            }
        } else if(p[j] == '.' || p[j] == s[i]){
            memo[key] = check(s, p, i+1, j+1, memo);
            return memo[key];
        }

        memo[key] = false;
        return false;
    }
public:
    bool isMatch(string s, string p) {
        unordered_map<string, bool> memo;
        return check(s, p, 0, 0, memo);
    }
};
