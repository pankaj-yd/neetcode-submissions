class Solution {
public:
    void rotate(vector<vector<int>>& arr){
        int m = arr.size(), n = arr[0].size();

        int l = 0, r = n-1, t = 0, b = m-1;
        while(l < r && t < b){
        for(int i = 0; i < (r - l); i++){
            int tmp = arr[t][l + i];
            arr[t][l + i] = arr[b - i][l];
            arr[b - i][l] = arr[b][r - i];
            arr[b][r - i] = arr[t + i][r];
            arr[t + i][r] = tmp;
        }
        l++, r--, t++, b--;
        }

    }
};
