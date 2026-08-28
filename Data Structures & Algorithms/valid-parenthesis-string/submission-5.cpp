class Solution {
private:
    bool dfs(string &s, int i, int open){
        if(open < 0){
            return false;
        }

        if(i == s.size()){
            if(open == 0) return true;
            return false;
        }

        if(s[i] == '('){
            return dfs(s, i+1, open+1);
        } else if(s[i] == ')'){
            return dfs(s, i+1, open-1);
        } else {
            return dfs(s, i+1, open+1) || dfs(s, i+1, open-1) || dfs(s, i+1, open);
        }
    }

public:
    bool checkValidString(string s){
        return dfs(s, 0, 0);
    }
};
