class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr){
        int m = arr.size(), n = arr[0].size();

        vector<int> ans;

        int l = 0, r = n-1, t = 0, b = m-1;

        while(l <= r && t <= b){
            for(int i = l; i <= r ; i++){
                ans.push_back(arr[t][i]);
            }
            t++;
            if(t > b){break;}

            for(int j = t; j <= b; j++){
                ans.push_back(arr[j][r]);
            }
            r--;
            if(r < l){break;}

            for(int i = r; i >= l; i--){
                ans.push_back(arr[b][i]);
            }
            b--;
            if(b < t){break;}

            for(int j = b; j >= t; j--){
                ans.push_back(arr[j][l]);
            }
            l++;

        }

        return ans;
    }
};
