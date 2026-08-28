class Solution {
    int calc(vector<int> &nums, int target, int i, unordered_map<string, int> &umap){
        if(target == 0 && i == nums.size()){
            return 1;
        } else if(i == nums.size()){
            return 0;
        }
        string key = to_string(i) + "-" + to_string(target);
        if(umap.find(key) != umap.end()){
            return umap[key];
        }
        int pos = calc(nums, target + nums[i], i+1, umap);
        int neg = calc(nums, target - nums[i], i+1, umap);
        umap[key] = pos + neg;
        return pos + neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string, int> umap;
        return calc(nums, target, 0, umap);
    }
};
