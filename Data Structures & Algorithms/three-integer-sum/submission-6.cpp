class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            while(i > 0 && nums[i] == nums[i-1]){
                i++;
            }
            if(nums[i] > 0) break;
            int l = i+1;
            int r = n-1;
            while(l < r){

                if(nums[i] + nums[l] + nums[r] == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]){
                        l++;
                    }
                    l++;
                    r--;
                }
                if(nums[l] + nums[r] < -nums[i]){
                    l++;
                }
                if(nums[l] + nums[r] > -nums[i]){
                    r--;
                }
            }
        }

        return ans;
    }
};
