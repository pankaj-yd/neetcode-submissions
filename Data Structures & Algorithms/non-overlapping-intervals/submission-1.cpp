class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int start = arr[0][0];
        int end = arr[0][1];

        int count = 0;
        int i = 1;
        while(i < n){
            if(end <= arr[i][0]){
                // move to next index
                end = arr[i][1];
                start = arr[i][0];
            } else if( arr[i][0] < end && end <= arr[i][1]){
                count++;
            } else if(end > arr[i][1]){
                count++;
                end = arr[i][1];
                start = arr[i][0];
            }
            i++;
        }

        return count;
    }
};
