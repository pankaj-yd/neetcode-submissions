class Solution {

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int> >q;

        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        int lvl = 1;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int k = q.size();

            for(int i = 0; i < k; i++){
                pair<int, int> curr = q.front();
                q.pop();
                
                for(pair<int, int> dir : dirs){
                    int x = curr.first + dir.first;
                    int y = curr.second + dir.second;
                    if(x >= 0 && x < m && y >= 0 && y < n ){
                        
                        if(grid[x][y] < lvl){
                            continue;
                        }
                        grid[x][y] = lvl;
                        
                        q.push({x, y});
                    }
                }
            }
            lvl++;
        }

    }
};
