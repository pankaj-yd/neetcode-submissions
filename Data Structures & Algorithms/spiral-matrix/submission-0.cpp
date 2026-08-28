class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        
        vector<int> ans;
        int l = 0, r = n, t = 0, b = m;
        while(l < r && t < b){
            // top row
            for(int i = l; i < r; i++){
                ans.push_back(arr[t][i]);
            }
            t++;
            // right col except bottom right
            for(int i = t; i < b; i++){
                ans.push_back(arr[i][r-1]);
            }
            r--;
            
            if( !(l < r && t < b) ) break;


            // bottom row
            for(int i = r-1; i >= l; i--){
                ans.push_back(arr[b-1][i]);
            }
            b--;
            // left col 
            for(int i = b-1; i >= t; i--){
                ans.push_back(arr[i][l]);
            }
            l++; 
        }

        return ans;
    }
};
