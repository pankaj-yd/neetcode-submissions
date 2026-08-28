class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int start = newInterval[0];
        int end = newInterval[1];
        int done = 0;
        bool inserted = false;
        for(int i = 0; i < n; i++){
            if(end < intervals[i][0]){
                ans.push_back({start, end});
                ans.push_back(intervals[i]);
                done = i;
                inserted = true;
                break;
            } else if(intervals[i][0] <= end && end <= intervals[i][1]){
                end = intervals[i][1];
                start = min(start, intervals[i][0]);
                ans.push_back({start, end});
                done = i;
                inserted = true;
                break;
            } else if(start > intervals[i][1]){
                ans.push_back(intervals[i]);
                done = i;
            } else{
                start = min(start, intervals[i][0]);
                done = i;
                // cout << "here: " << start;
            }
        }

        if(!inserted) ans.push_back({start, end});

        // cout << "ans: " << ans.size() << endl;
        for(int i = done + 1; i < n; i++){
            // cout << "here i: " << i;
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};
