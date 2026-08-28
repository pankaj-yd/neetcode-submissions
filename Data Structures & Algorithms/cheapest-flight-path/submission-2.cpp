class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(k >= 0){
            queue<pair<int, int>> q;
            for(vector<int> flight : flights){
                if(dist[flight[0]] != INT_MAX){
                    int newDist = dist[flight[0]] + flight[2];
                    if(dist[flight[1]] > newDist){
                        q.push({flight[1], newDist});
                    }
                }
            }

            while(!q.empty()){
                pair<int, int> front = q.front();
                q.pop();
                dist[front.first] = min(dist[front.first], front.second);
            }
            k--;
        }
        if(dist[dest] == INT_MAX){
            return -1;
        }
        return dist[dest];
    }
};
