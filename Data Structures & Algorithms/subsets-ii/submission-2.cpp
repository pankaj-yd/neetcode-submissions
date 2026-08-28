class Solution {
private:
    void allsubsets(set<vector<int>> &res, vector<int>& nums, vector<int> &curr, int i){
        if(i == nums.size()){
            res.insert(curr);
            return;
        }

        // include nums[i]
        curr.push_back(nums[i]);
        allsubsets(res, nums, curr, i+1);
        curr.pop_back();

        // proceed without nums[i]
        allsubsets(res, nums, curr, i+1);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        vector<int> curr;
        allsubsets(res, nums, curr, 0);

        return vector<vector<int>>(res.begin(), res.end());
    }
};
