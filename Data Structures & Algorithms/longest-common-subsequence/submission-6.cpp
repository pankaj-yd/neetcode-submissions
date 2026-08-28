class Solution {
/*
    lcs(s, t, i, j) {
        if s[i] == t[j] {
            ans = 1 + lcs(s, t, i+1, j + 1);
        } else {
            ans = max( lcs(s, t, i, j+1),  lcs(s, t, i+1, j) )
        }

    }

*/
public:
    int longestCommonSubsequence(string s, string t){
        int n = s.size(), m = t.size();
        vector<int> dp(m+1, 0);
        // fill rest of dp
        for(int i = n-1; i >= 0; i--){
            int jPlusOne = 0;
            for(int j = m-1; j >= 0; j--){
                int tmp = dp[j];
                if(s[i] == t[j]){
                    dp[j] = 1 + jPlusOne;
                } else {
                    dp[j] = max(dp[j+1],  tmp);
                }
                jPlusOne = tmp;
            }
        }

        return dp[0];
    }
};
