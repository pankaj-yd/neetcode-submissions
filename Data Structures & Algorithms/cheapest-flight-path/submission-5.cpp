class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        for(int i = 0; i <= k; i++){
            vector<int> newDist = dist;
            for(vector<int> flight : flights){
                int u = flight[0], v = flight[1], w = flight[2];
                if(dist[u] != INT_MAX && dist[u] + w < newDist[v]){
                    newDist[v] = dist[u] + w;
                }
            }
            dist = newDist;
        }

        if(dist[dest] == INT_MAX) return -1;
        return dist[dest];
    }
};
