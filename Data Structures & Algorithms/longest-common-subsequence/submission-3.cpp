class Solution {
public:
    int longestCommonSubsequence(string s, string t){
        int n = s.size(), m = t.size();
        vector<int> dp(m, 0);
        dp[0] = s[0] == t[0];
        // set first row
        for(int j = 1; j < m; j++){
            dp[j] = dp[j-1] | s[0] == t[j];
        }

        // fill rest of dp
        for(int i = 1; i < n; i++){
            vector<int> newDp(m, 0);
            newDp[0] = dp[0] | (s[i] == t[0]);
            for(int j = 1; j < m; j++){
                int ans = 0;
                if(s[i] == t[j]){
                    ans = 1 + dp[j-1];
                }
                ans = max({ans, dp[j], newDp[j-1]});
                newDp[j] = ans;
            }
            dp = newDp;
        }

        return dp[m-1];
    }
};
