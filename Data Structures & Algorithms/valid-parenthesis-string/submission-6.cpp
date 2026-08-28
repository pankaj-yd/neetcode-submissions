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
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        dp[n][0] = true;
        
        for(int i = n-1; i >= 0; i--){
            for(int open = 0; open < n; open++){
                int res = false;
                if(s[i] == '('){
                    res |= dp[i+1][open+1];
                } else if(s[i] == ')'){
                    if(open-1 >= 0) res |= dp[i+1][open-1];
                } else {
                    res  |= dp[i+1][open+1] | dp[i+1][open];
                    if(open-1 >= 0) res |= dp[i+1][open-1];
                }
                dp[i][open] = res;
            }
        }


        return dp[0][0];
    }
};
