class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        int freshFruits = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    freshFruits++;
                }
            }
        }
        int time = 0;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty() && freshFruits > 0){
            int n = q.size();

            for(int i = 0; i < n; i++){
                pair<int, int> rotten = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    int x = rotten.first + dirs[j][0];
                    int y = rotten.second + dirs[j][1];

                    if(x >= rows || y >= cols || x < 0 || y < 0 || grid[x][y] != 1 ){
                        continue;
                    }
                    grid[x][y] = -1;
                    freshFruits--;
                    q.push({x, y});

                }
            }
            time++;
        }
        if (freshFruits > 0){
            return -1;
        }
        return time;
    }
};
