class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int sum = -nums[i];
            int l = i+1;
            int r = n-1;
            while(l < r){
                if(nums[l] + nums[r] == sum){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int val = nums[l];
                    int rval = nums[r];
                    while(nums[l] == val) {l++;}
                    while(nums[r] == val) {r--;}
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
