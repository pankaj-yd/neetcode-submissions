
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            if(umap.find(target - nums[i]) != umap.end()){
                int idx = umap[target - nums[i]];
                return {min(i, idx), max(i, idx)};
            }
            umap.insert({nums[i], i});
        }

        return {-1, -1};
    }
};
