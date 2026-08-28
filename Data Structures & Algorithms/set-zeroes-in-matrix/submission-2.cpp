class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();

        
        int rowZero = false;
        for(int i = 0; i < m; i++){
            int thisrowZero = false;
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 0){
                    thisrowZero = true;
                    arr[0][j] = 0;

                    if(i == 0) rowZero = true;
                }
            }

            if(i != 0 && thisrowZero){
                std::fill(arr[i].begin(), arr[i].end(), 0);
            }
        }

        for(int j = n-1; j >= 0; j--){
            if(arr[0][j] == 0){
                for(int i = 0; i < m; i++){
                    arr[i][j] = 0;
                }
            }
        }

        if(rowZero) std::fill(arr[0].begin(), arr[0].end(), 0);
    }
};
