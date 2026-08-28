class Solution {
public:
    int longestCommonSubsequence(string s, string t){
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = s[0] == t[0];
        // set first row
        for(int j = 1; j < m; j++){
            if(s[0] == t[j]){
                dp[0][j] = 1;
            } else {
                dp[0][j] = dp[0][j-1];
            }
        }

        // set first col
        for(int i = 1; i < n; i++){
            if(s[i] == t[0]){
                dp[i][0] = 1;
            } else {
                dp[i][0] = dp[i-1][0];
            }
        }

        // fill rest of dp
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                int ans = 0;
                if(s[i] == t[j]){
                    ans = 1 + dp[i-1][j-1];
                }
                ans = max({ans, dp[i-1][j], dp[i][j-1]});
                dp[i][j] = ans;
            }
        }

        return dp[n-1][m-1];
    }
};
