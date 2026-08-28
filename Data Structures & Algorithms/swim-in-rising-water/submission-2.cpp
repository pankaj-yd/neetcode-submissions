class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int ans = grid[0][0];

        auto cmp = [&](pair<int, int> &a, pair<int, int> &b){
            return grid[a.first][a.second] > grid[b.first][b.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        minHeap.push({0, 0});

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        // int count = 1;
        while(!minHeap.empty()){
            pair<int, int> top = minHeap.top();
            minHeap.pop();
            ans = max(ans, grid[top.first][top.second]);
            // cout << top.first << " " << top.second << endl;
            if(top.first == n-1 && top.second == n-1){
                break;
            }

            visited[top.first][top.second] = true;
            for(pair<int, int> dir : dirs){
                int x = top.first + dir.first;
                int y = top.second + dir.second;

                if(x < 0 || x >= n || y < 0 || y >= n || visited[x][y]){
                    continue;
                }

                minHeap.push({x, y});
            }

            // if(count > 10) break;

            // count++;

        }


        return ans;
    }
};
