class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses+1, vector<int>());
        vector<int> lvl(numCourses + 1, -1);

        for(vector<int> v : prerequisites){
            graph[v[1]].push_back(v[0]);
        }
        int count = 0;
        for(int i = 1; i <= numCourses; i++){
            if(lvl[i] != -1){
                continue;
            }
            int start = count;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int n = q.size();

                for(int i = 0; i < n; i++){
                    int v = q.front();
                    q.pop();
                    if(lvl[v] == -1){
                        lvl[v] = count++;
                    } else if(lvl[v] >= start){
                        return false;
                    }
                    for(int neigh : graph[v]){
                        q.push(neigh);
                    }
                }

            }

        }
        return true;

    }
};
