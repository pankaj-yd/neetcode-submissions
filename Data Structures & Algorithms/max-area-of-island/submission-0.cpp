class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols){
        cout << i << " " << j << endl;
        if( i >= rows || i < 0 || j >= cols || j < 0 || grid[i][j] == 0){
            return 0;
        }

        int area = 1;
        grid[i][j] = 0;
        area += dfs(grid, i+1, j, rows, cols);
        area += dfs(grid, i-1, j, rows, cols);
        area += dfs(grid, i, j+1, rows, cols);
        area += dfs(grid, i, j-1, rows, cols);

        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(grid, i, j, rows, cols));
                }
            }
        }

        return ans;
    }
};
