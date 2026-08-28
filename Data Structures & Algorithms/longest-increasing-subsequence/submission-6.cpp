class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        if (n == 0){
            return 0;
        }

        // numVal, lenOfLIS
        vector<pair<int,int>> lis;
        int ans = 1;
        lis.push_back({nums[0], 1});
        for(int i = 1; i < n; i++){
            int currLen = 1;
            for(int j = lis.size() - 1; j >= 0; j--) {
                if (lis[j].first < nums[i]){
                    currLen = max(currLen, lis[j].second + 1);
                }
            }
            lis.push_back({nums[i], currLen});
            ans = max(ans, currLen);
        }

        return ans;
    }
};
