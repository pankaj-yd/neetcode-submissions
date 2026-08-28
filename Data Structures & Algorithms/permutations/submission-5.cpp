class Solution {
private:
    vector<vector<int>> perms(vector<int>& nums, int idx){
        if(idx == nums.size()){
            return {{}};
        }

        vector<vector<int>> ans = perms(nums, idx + 1);
        vector<vector<int>> res;
        
        for(vector<int> v : ans){
            int n = v.size();
            for(int i = 0; i <= n; i++){
                vector<int> tmp;
                for(int num : v){
                    if(tmp.size() == i){
                        tmp.push_back(nums[idx]);
                    }
                    tmp.push_back(num);
                }
                if(tmp.size() == n){
                    tmp.push_back(nums[idx]);
                }
                res.push_back(tmp);
            }
        }


        return res;
    }
public:
    vector<vector<int>> permute(vector<int>& nums){
        return perms(nums, 0);

    }
};
