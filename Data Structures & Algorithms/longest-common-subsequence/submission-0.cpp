class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int lcs[m][n];
        memset(lcs, 0, sizeof(lcs));

        lcs[0][0] = s[0] == t[0];
        for(int i = 1; i < m; i++){
            lcs[i][0] = lcs[i-1][0] || s[i] == t[0];
        }
        for(int j = 1; j < n; j++){
            lcs[0][j] = lcs[0][j-1] || s[0] == t[j];

        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(s[i] == t[j]){
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                    
                }
                lcs[i][j] = max(lcs[i][j], max(lcs[i-1][j], lcs[i][j-1]));
            }
        }

        return lcs[m-1][n-1];
    }
};
