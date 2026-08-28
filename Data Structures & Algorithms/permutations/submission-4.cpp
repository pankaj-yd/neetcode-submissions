class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        if (nums.size() == 1) {
            res.push_back({nums[0]});
            return res;
        }

        vector<int> remainingNums(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(remainingNums);

        cout << "Starting" << endl;
        for(auto perm : perms){
            
            for(int ele : perm)
             cout << ele << " ";
             cout << endl;

            for(int i = 0; i <= perm.size(); i++){
                vector<int> newPerm;
                for( int ele : perm){
                    if(newPerm.size() == i){
                        newPerm.push_back(nums[0]);
                    }
                    newPerm.push_back(ele);
                }
                if(newPerm.size() == perm.size()){
                    newPerm.push_back(nums[0]);
                }
                cout << "answer" << endl;
                for(int ele : newPerm)
                cout << ele << " ";
                cout << endl;
                res.push_back(newPerm);
            }
        }
        return res;
    }
};
