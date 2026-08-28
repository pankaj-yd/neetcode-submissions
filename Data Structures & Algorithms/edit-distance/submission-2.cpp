class Solution {
    int memo[101][101];
private:
    int calc(string &s, string &t, int i, int j){
        if(j == t.size()) {
            return s.size() - i;
        }
        if(i == s.size()) {
            return t.size() - j;
        }

        // cout << i << "," << j << " -> ";
        if(memo[i][j] != -1) return memo[i][j];
        int count = INT_MAX;
        if(s[i] == t[j]){
            count = min(count, calc(s, t, i+1, j+1));
            memo[i][j] = count;
            return count;
        }
        // insert character
        count = min(count, 1 + calc(s, t, i, j+1));

        // delete character
        count = min(count, 1 + calc(s, t, i+1, j));

        // replace character
        count = min(count, 1 + calc(s, t, i+1, j+1));

        memo[i][j] = count;
        // cout << endl;
        return count;
    }
public:
    int minDistance(string s, string t) {
        memset(memo, -1, sizeof(memo));
        return calc(s, t, 0 ,0);
    }
};
