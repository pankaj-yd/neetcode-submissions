class Solution {
private:
    void calc(vector<int>& nums, int i, vector<vector<int>> &ans, vector<int> &curr){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        calc(nums, i+1, ans, curr);
        curr.pop_back();

        while(i < nums.size() -1 && nums[i] == nums[i+1]){
            i++;
        }
        calc(nums, i+1, ans, curr);

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(), nums.end());

         vector<vector<int>> ans;
         vector<int> curr;

         calc(nums, 0, ans, curr);

         return ans;
    }
};
