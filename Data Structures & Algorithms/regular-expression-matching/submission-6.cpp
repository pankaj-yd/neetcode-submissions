class Solution {
private:
    bool check(string &s, string &p, int i, int j, vector<vector<int>> &memo){
        cout << i << "," << j << "  ->  " ;
        if(j >= p.size() && i >= s.size()) return true;
        if(j >= p.size()) return false;

        if(i == s.size()){
            if(j < p.size() - 1 && p[j+1] == '*' && j + 2 == p.size()){
                return true;
            }else {
                return false;
            }
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }
        

        
        bool path1 = false;
        if(j < p.size() - 1 && p[j+1] == '*'){
            // match one time
            if( (p[j] == '.' || p[j] == s[i] ) ){
                if(check(s, p, i+1, j, memo)){
                    memo[i][j] = true;
                    return true;
                }
                
            }

            // match 0 times
            if(check(s, p, i, j+2, memo)){
                memo[i][j] = true;
                return true;
            }
        } else if(p[j] == '.' || p[j] == s[i]){
            memo[i][j] = check(s, p, i+1, j+1, memo);
            return memo[i][j];
        }

        memo[i][j] = false;
        return false;
    }
public:
    bool isMatch(string s, string p) {

        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        return check(s, p, 0, 0, memo);
    }
};
