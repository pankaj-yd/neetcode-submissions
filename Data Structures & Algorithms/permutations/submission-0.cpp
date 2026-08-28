class Solution {
private:
    void perm(deque<vector<int>> &res, vector<int>& nums, int i){
        if(i == nums.size() - 1){
            res.push_back({nums[i]});
            return;
        }
        perm(res, nums, i+1);
        int n = res.size();
        while(n > 0){
            vector<int> perm = res.front();
            res.pop_front();
            int j = perm.size();
            int k = 0;
            for(int k = 0; k <= j; k++){
                vector<int> newPerm;
                for(int ele : perm){
                    if(newPerm.size() == k){
                        newPerm.push_back(nums[i]);
                    }
                    newPerm.push_back(ele);
                }
                if(newPerm.size() != j+1){
                    newPerm.push_back(nums[i]);
                }
                res.push_back(newPerm);
            }
            n--;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        deque<vector<int>> res;
        perm(res, nums, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
};
