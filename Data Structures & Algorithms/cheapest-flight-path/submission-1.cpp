class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int,int>>> g(n, vector<pair<int,int>>());

        for(vector<int> flight : flights){
            g[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<int> q;
        q.push(src);

        while(!q.empty() && k >= 0){
            int n = q.size();
            queue<pair<int, int>> toUpdate;
            for(int i = 0; i < n; i++){
                int top = q.front();
                q.pop();

                for(pair<int,int> nei : g[top]){
                    if (dist[top] == INT_MAX){
                        break;
                    }
                    int newDist = dist[top] + nei.second;
                    if(dist[nei.first] > newDist){
                        toUpdate.push({nei.first, newDist});
                        q.push({nei.first});
                    }
                }
            }
            while(!toUpdate.empty()){
                pair<int, int> front = toUpdate.front();
                toUpdate.pop();
                dist[front.first] = min(dist[front.first], front.second);
            }
            k--;
        }

        if(dist[dest] == INT_MAX) return -1;
        return dist[dest];
    }
};
