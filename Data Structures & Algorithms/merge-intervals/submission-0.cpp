class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        int n = arr.size();
        int start = arr[0][0], end = arr[0][1];

        int i = 1;
        while(i <= n){
            if(i == n){
                ans.push_back({start, end});
                return ans;
            }
            cout << end << endl;
            if(end < arr[i][0]){
                ans.push_back({start, end});
                start = arr[i][0];
                end = arr[i][1];    
            } else if(arr[i][0] <= end && end <= arr[i][1]){
                end = arr[i][1];
                start = min(start, arr[i][0]);
            } else{
                start = min(start, arr[i][0]);
            }

            i++;
        }

        return ans;

    }
};
