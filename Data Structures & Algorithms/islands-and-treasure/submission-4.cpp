class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int count){
        
        int rows = grid.size();
        int cols = grid[0].size();
        if(i >= rows || i < 0 || j >= cols || j < 0 || grid[i][j] == -1 ){
            return;
        }
        cout << "i: " << i << " ,j: " << j << endl;
        cout << "grid[i][j]: " << grid[i][j] << " , count: " << count << endl;

        if(grid[i][j] == 0 ||  grid[i][j] > count){
            if(grid[i][j] > count){
                grid[i][j] = count;
            }
            dfs(grid, i-1, j, count + 1);
            dfs(grid, i+1, j, count + 1);
            dfs(grid, i, j-1, count + 1);
            dfs(grid, i, j+1, count + 1);
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    // apply dfs
                    dfs(grid, i, j, 0);
                }
            }
        }
    }
};
