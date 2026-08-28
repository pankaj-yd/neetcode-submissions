class Solution {
    int ans = 0;
private:
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &memo){
        int m = matrix.size(), n = matrix[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n){
            return 0;
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int count = 0;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int k = 0; k < 4; k++){
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]){
                count = max(count, dfs(matrix, x, y, memo));
            }
        }
        memo[i][j] = 1 + count;
        ans = max(ans, memo[i][j]);
        return memo[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        dfs(matrix, 0, 0, memo);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(memo[i][j] == -1){
                    dfs(matrix, i, j, memo);
                }
            }
            
        }
        return ans;
    }
};
