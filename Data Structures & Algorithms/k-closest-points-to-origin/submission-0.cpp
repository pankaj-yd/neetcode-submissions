class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>> > maxHeap;

        int n = points.size();
        for(int i = 0; i < n; i++){
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxHeap.push({d, i});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while( ! maxHeap.empty() ){
            ans.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return ans;
    }
};
