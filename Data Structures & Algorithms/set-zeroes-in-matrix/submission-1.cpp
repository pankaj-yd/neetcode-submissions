class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();

        vector<bool> cols(n, false);

        for(int i = 0; i < m; i++){
            bool rowzero = false;
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 0){
                    rowzero = true;
                    cols[j] = true;
                }
            }

            if(rowzero){
                std::fill(arr[i].begin(), arr[i].end(), 0);
            }
        }

        for(int j = 0; j < n; j++){
            if(cols[j]){
                for(int i = 0; i < m; i++){
                    arr[i][j] = 0;
                }
            }
        }
    }
};
