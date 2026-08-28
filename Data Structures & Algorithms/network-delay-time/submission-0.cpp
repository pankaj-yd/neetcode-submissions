class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n+1, vector<pair<int,int>> ());

        for(vector<int> v : times){
            g[v[0]].push_back({v[1], v[2]});
        }
        
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({time[k], k});

        while( !minHeap.empty()){
            pair<int,int> top = minHeap.top();
            minHeap.pop();

            for(pair<int, int> v : g[top.second]){
                int vTime = time[v.first];
                int calcTime = time[top.second] + v.second;
                if(vTime > calcTime){
                    time[v.first] = calcTime;
                    minHeap.push({calcTime, v.first});
                }
            }
        }

        int totalTime = 0;
        for(int i = 1; i <= n; i++){
            if(time[i] == INT_MAX){
                return -1;
            }
            totalTime = max(totalTime, time[i]);
        }

        return totalTime;
    }
};
