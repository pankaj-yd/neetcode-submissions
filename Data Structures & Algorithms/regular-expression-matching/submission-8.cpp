class Solution {
private:
    bool match(string &s, int i, string &p, int j, vector<vector<int>> &dp){
        int m = s.size(), n = p.size();
        if(i >= m && j >= n){
            return true;
        } else if(j >= n || i >= m) {
            return false;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        } 

        bool ans = false;
        if(s[i] == p[j] || p[j] == '.'){
            if(p[j+1] == '*'){
                ans = match(s, i+1, p, j, dp) || match(s, i+1, p, j+2, dp);
            } else {
                ans =  match(s, i+1, p, j+1, dp);
            }
        } else if(j < n-1 && p[j+1] == '*'){
            ans = match(s, i, p, j+2, dp);
        }
        dp[i][j] = ans;
        return ans;
    }
public:
    bool isMatch(string s, string p){
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return match(s, 0, p, 0, dp);
    }
};
