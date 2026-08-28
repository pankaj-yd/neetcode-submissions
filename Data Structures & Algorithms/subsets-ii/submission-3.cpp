class Solution {
private:
    void allsubsets(vector<vector<int>> &res, vector<int>& nums, vector<int> &curr, int i){
        if(i >= nums.size()){
            res.push_back(curr);
            return;
        }

        // include nums[i]
        int j = i+1;
        while(j < nums.size() && nums[j] == nums[i]){
            j++;
        }

        for(int k = i; k < j; k++){
            curr.push_back(nums[i]);
            allsubsets(res, nums, curr, j);
        }

        for(int k = i; k < j; k++){
            curr.pop_back();
        }

        // proceed without nums[i]
        allsubsets(res, nums, curr, j);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        allsubsets(res, nums, curr, 0);

        return res;
    }
};
