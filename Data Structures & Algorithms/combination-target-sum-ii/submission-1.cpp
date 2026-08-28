class Solution {
private:
    void calc(vector<int>& nums, int idx, int target, vector<int> &curr, vector<vector<int>> &ans){
        // for(int i = 0; i < curr.size(); i++){
        //     cout << curr[i] << " ";
        // }
        // cout << endl;
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(idx >= nums.size() || target < 0) return;
        

        curr.push_back(nums[idx]);
        calc(nums, idx+1, target - nums[idx], curr, ans);
        curr.pop_back();

        while(idx < nums.size() - 1 && nums[idx] == nums[idx + 1]){
            idx++;
        }
        calc(nums, idx + 1, target, curr, ans);

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        calc(nums, 0, target, curr, ans);
        return ans;
    }
};
