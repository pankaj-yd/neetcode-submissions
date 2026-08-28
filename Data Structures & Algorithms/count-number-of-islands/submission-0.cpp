class Solution {
private:
    bool dfs(vector<vector<char>>& grid, int i, int j){
        bool ans = false;
        int rows = grid.size(), cols = grid[0].size();
        if( i >= rows || i < 0 || j >= cols || j < 0){
            return 0;
        }

        
        if(grid[i][j] == '1'){
            grid[i][j] = '0';

            dfs(grid, i+1, j);
            dfs(grid, i-1, j);
            dfs(grid, i, j+1);
            dfs(grid, i, j-1);
            
            ans = true;
        }

        return ans;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size(), cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(dfs(grid, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};
