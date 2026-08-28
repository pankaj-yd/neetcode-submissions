class Solution {
private:
    int calc(string &s, string &t, int i, int j){
        if(j == t.size()) {
            return 1;
        } else if(i == s.size()){
            return 0;
        }
        
        int count = 0;
        if(s[i] == t[j]){
            count += calc(s, t, i+1, j+1);
        }
        count += calc(s, t, i+1, j);

        return count;
    }
public:
    int numDistinct(string s, string t) {
        int p = s.size(), q = t.size();
        if(p < q) return 0;
        
        vector<int> dp(q+1, 0);
        dp[q] = 1;

        for(int i = p-1; i >= 0; i--){
            vector<int> newDP(q+1, 0);
            newDP[q] = 1;
            for(int j = q-1; j >=0; j--){
                newDP[j] = dp[j];
                if(s[i] == t[j]){
                    newDP[j] += dp[j+1];
                }
            }
            dp = newDP;
        }
        
        
        return dp[0];
    }
};
