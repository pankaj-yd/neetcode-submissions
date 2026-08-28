class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& arr, vector<int>& t) {
        int n = arr.size();
        vector<int> ans ={0, 0, 0};
        for(vector<int> &v : arr){
            if(v[0] > t[0] || v[1] > t[1] || v[2] > t[2]){
                continue;
            }
            if(v[0] == t[0] || v[1] == t[1] || v[2] == t[2]){
                ans[0] = max(ans[0], v[0]);
                ans[1] = max(ans[1], v[1]);
                ans[2] = max(ans[2], v[2]);
            }

            if(ans[0] == t[0] && ans[1] == t[1] && ans[2] == t[2]) return true;
        }

        return false;
    }
};
