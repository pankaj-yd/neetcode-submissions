class Solution {
// private:
//     int calc(string &s, string &t, int i, int j){
//         if(j == t.size()) {
//             return s.size() - i;
//         }
//         if(i == s.size()) {
//             return t.size() - j;
//         }

//         // cout << i << "," << j << " -> ";
//         if(memo[i][j] != -1) return memo[i][j];
//         int count = INT_MAX;
//         if(s[i] == t[j]){
//             count = min(count, calc(s, t, i+1, j+1));
//             memo[i][j] = count;
//             return count;
//         }
//         // insert character
//         count = min(count, 1 + calc(s, t, i, j+1));

//         // delete character
//         count = min(count, 1 + calc(s, t, i+1, j));

//         // replace character
//         count = min(count, 1 + calc(s, t, i+1, j+1));

//         memo[i][j] = count;
//         // cout << endl;
//         return count;
//     }
public:
    int minDistance(string s, string t) {
        int dp[s.size() + 1][t.size()+1];
        memset(dp, 0, sizeof(dp));
        int p = s.size(), q = t.size();

        for(int i = 0; i <= p; i++){
            dp[i][q] = p - i;
        }

        for(int j = 0; j <= q; j++){
            dp[p][j] = q - j;
        }

        for(int i = p-1; i >= 0; i--){
            for(int j = q-1; j >= 0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};
