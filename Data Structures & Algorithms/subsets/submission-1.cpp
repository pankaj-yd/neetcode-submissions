class Solution {
private:
    void allSubsets(vector<vector<int>> &res, vector<int> &curr, vector<int>& nums, int i){
        if( i == nums.size() ){
            res.push_back(curr);
            return;
        }
        
        allSubsets(res, curr, nums, i + 1);

        curr.push_back(nums[i]);
        allSubsets(res, curr, nums, i + 1);
        curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        vector<int> curr;
        allSubsets(res, curr, nums, 0);

        return res;
    }
};
