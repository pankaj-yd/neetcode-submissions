class Solution {
private:
    bool dfs(string &s, string &t, string &u, int i, int j, int k, unordered_map<string, bool> umap){
        int p = s.size(), q = t.size(), r = u.size();

        if(k == r) {
            // cout << "at end" << endl;
            return true;
        }

        string key = to_string(i) + "-" + to_string(j);
        if(umap.find(key) != umap.end()){
            // cout << key << endl;
            return umap[key];
        }
        int tmp = k;
        for(int l = i; l < p; l++){
            if(s[l] == u[tmp]){
                if(dfs(s, t, u, l + 1, j, tmp + 1, umap)) {
                    // cout << key << endl;
                    umap[key] = true;
                    return true;
                }
            } else {
                break;
            }
            tmp++;
        }

        tmp = k;
        for(int l = j; l < q; l++){
            if(t[l] == u[tmp]){
                if(dfs(s, t, u, i, l+1, tmp+1, umap)) {
                    // cout << key << endl;
                    umap[key] = true;
                    return true;
                }
            } else{
                break;
            }
            tmp++;
        }

        umap[key] = false;
        // cout << key << "not found"<< endl;
        return false;
    }
public:
    bool isInterleave(string s, string t, string u) {
        int p = s.size(), q = t.size(), r = u.size();
        if(p + q != r) return false;
        
        bool dp[p+1][q+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        for(int i = 0; i <= p; i++){
            for(int j = 0; j <= q; j++){
                if(i > 0  && dp[i-1][j] && s[i-1] == u[i + j-1]){
                    dp[i][j] = true;
                }
                if(j > 0 && dp[i][j-1] && t[j-1] == u[i + j-1]){
                    dp[i][j] = true;
                }
            }
        }

        return dp[p][q];
    }
};
