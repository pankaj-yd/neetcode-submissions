class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> parent(n, vector<int>(n, -1) );

        auto comp = [](vector<int> &a, vector<int> &b){
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

        minHeap.push({grid[0][0], 0, 0});

        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        parent[0][0] = -2;
        while(!minHeap.empty()){
            vector<int> top = minHeap.top();
            minHeap.pop();
            cout << "processing: " << top[1] << " " << top[2] << endl;
            if(top[1] == n-1 && top[1] == top[2]){
                break;
            }

            for(int i = 0; i < 4; i++){
                int x = top[1] + dirs[i][0];
                int y = top[2] + dirs[i][1];
                if(x < 0 || x >= n || y < 0 || y >= n){
                    continue;
                }
                if(parent[x][y] != -1){
                    continue;
                }
                int cord = n * top[1] + top[2];
                parent[x][y] = cord;
                minHeap.push({grid[x][y], x, y});
            }
        }

        int x = n-1, y = n-1;
        int ans = grid[x][y];
        while(true){
            int cord = parent[x][y];
            if(cord == -2){
                break;
            }
            x = cord/n;
            y = cord%n;
            ans = max(ans, grid[x][y]);
        }
        return ans;
    }
};
