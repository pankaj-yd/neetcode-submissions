class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        int n = points.size();

        auto cmp = [](vector<int> &a, vector<int> &b){
            return a[2] > b[2]; 
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for(int i = 1; i < n; i++){
            pq.push({0, i, abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1])});
        }
        int cost = 0;
        vector<bool> visited(n, false);
        visited[0] = true;
        while(!pq.empty()){
            vector<int> top = pq.top();
            pq.pop();

            if(!visited[top[1]]){
                cost += top[2];
                visited[top[1]] = true;

                for(int i = 0; i < n; i++){
                    if(!visited[i]){
                        pq.push({top[1], i, abs(points[top[1]][0] - points[i][0]) + abs(points[top[1]][1] - points[i][1])});
                    }
                }
            }
        }

        return cost;
    }
};
