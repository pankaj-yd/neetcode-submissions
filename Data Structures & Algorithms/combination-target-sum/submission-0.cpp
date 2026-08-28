class Solution {
private:
    void allSums(set<vector<int>> &res, vector<int>& nums, int t, int sum, int i, vector<int> &curr){
        if(t == sum){
            res.insert(curr);
            return;
        } else if( i == nums.size() || t < sum){
            return;
        }

        curr.push_back(nums[i]);
        allSums(res, nums, t, sum + nums[i], i, curr);

        allSums(res, nums, t, sum + nums[i], i + 1, curr);

        curr.pop_back();
        allSums(res, nums, t, sum, i + 1, curr);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        vector<int> curr = {};
        allSums(res, nums, target, 0, 0, curr);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
