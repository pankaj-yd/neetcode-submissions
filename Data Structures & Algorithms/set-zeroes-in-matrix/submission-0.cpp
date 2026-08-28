class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();

        vector<vector<int>> zero;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 0){
                    zero.push_back({i, j});
                }
            }
        }

        for(vector<int> idx : zero){
            int row = idx[0], col = idx[1];
            for(int i = 0; i < n; i++){
                arr[row][i] = 0;
            }
            for(int i = 0; i < m; i++){
                arr[i][col] = 0;
            }
        }
    }
};
