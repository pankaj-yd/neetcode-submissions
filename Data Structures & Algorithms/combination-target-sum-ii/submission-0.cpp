class Solution {
private:
    void comb(vector<vector<int>> &res, vector<int>& nums, int target, int i, vector<int> curr){
        if(target < 0){
            return;
        } else if(target == 0){
            res.push_back(curr);
            return;
        } else if(i == nums.size()){
            return;
        }

        
        // include nums[i]
        int j = i+1;
        while(j < nums.size() && nums[j] == nums[i]){
            j++;
        }
        for(int k = i; k < j; k++){
            curr.push_back(nums[i]);
            comb(res, nums, target - nums[i] * (k - i + 1), j, curr);
        }
        for(int k = i; k < j; k++){
            curr.pop_back();
        }
        

        // do not include nums[i]
        comb(res, nums, target, j, curr);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        comb(res, nums, target, 0, curr);
        return res;
    }
};
