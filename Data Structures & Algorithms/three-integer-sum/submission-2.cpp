class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) break;
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int sum = -nums[i];
            int l = i+1;
            int r = n-1;
            while(l < r){
                if(nums[l] + nums[r] == sum){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while(l < r && nums[l] == nums[l-1]) {l++;}

                } else if(nums[l] + nums[r] > sum) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
