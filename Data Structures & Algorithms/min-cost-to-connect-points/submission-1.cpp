class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int cost = 0;
        int count = 0;

        // min heap
        auto comp = [](vector<int> &a, vector<int> &b){
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

        for(int i = 1; i < n; i++){
            int dist = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
            minHeap.push({dist, 0, i});
        }
        vector<bool> visited(n, false);
        visited[0] = true;
        
        while(!minHeap.empty() && count < n-1){
            vector<int> top = minHeap.top();
            minHeap.pop();
            
            if(visited[top[2]]){
                continue;
            }
            
            count++;
            cost += top[0];
            cout << "cost: " << top[0] << " , " << top[1] << "->" << top[2] << endl;

            int currIdx = top[2];
            visited[currIdx] = true;
            for(int i = 0; i < n; i++){
                if(visited[i]){
                    continue;
                }
                int dist = abs(points[currIdx][0] - points[i][0]) + abs(points[currIdx][1] - points[i][1]);
                minHeap.push({dist, currIdx, i});
            }
        }

        return cost;
        
    }
};
