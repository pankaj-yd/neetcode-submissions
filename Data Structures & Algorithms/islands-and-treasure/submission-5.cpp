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
        
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    // apply dfs
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int lvl = 1;
        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i++){
                pair<int, int> top = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int x = top.first + dirs[i][0];
                    int y = top.second + dirs[i][1];
                    if(x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] != INT_MAX){
                        continue;
                    }
                    grid[x][y] = lvl;
                    q.push({x, y});
                }
            }
            lvl++;
            
        }
    }
};
