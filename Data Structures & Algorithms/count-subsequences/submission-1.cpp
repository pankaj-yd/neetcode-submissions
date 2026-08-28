class Solution {
private:
    int calc(string &s, int i, string &t, int j){
        if(j >= t.size()){
            return 1;
        }

        if(i >= s.size()){
            return 0;
        }
        

        int ans = 0;
        // use s[i]
        if(s[i] == t[j]){
            ans += calc(s, i+1, t, j+1);
        }

        // don't use s[i]
        ans += calc(s, i+1, t, j);

        return ans;
    }
public:
    int numDistinct(string s, string t){
        if(t.length() > s.length()) return 0;
        int m = s.size(), n = t.size();

        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i = m-1; i >= 0; i--){
            vector<int> newDp(n+1, 0);
            newDp[n] = 1;
            for(int j = n-1; j >= 0; j--){
                if(s[i] == t[j]){
                    newDp[j] += dp[j+1];
                }
                newDp[j] += dp[j];
            }
            dp = newDp;
        }
        return dp[0];
    }
};
