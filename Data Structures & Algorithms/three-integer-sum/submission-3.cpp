class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(), nums.end());
        for(int num : nums){
            cout << num << " ";
        }
        cout <<endl;
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                break;
            }
            int target = -(nums[i]);
            int l = i+1;
            int r = n-1;
            while( l < r){
                while(l < r && nums[l] == nums[l+1]){
                    l++;
                }
                while(l < r && nums[r] == nums[r-1]){
                    r--;
                }
                if(nums[l] + nums[r] == target){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } else if(nums[l] + nums[r] > target){
                    r--;
                } else {
                    l++;
                }

            }
            while(nums[i] == nums[i+1]){
                i++;
            }
        }
        return res;
    }
};
