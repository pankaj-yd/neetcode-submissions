struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        unordered_map<int, vector<int> > mp;
        for(int i = 0; i < n; i++) {
            if( mp.find(nums[i]) == mp.end() ){
                mp[nums[i]].push_back(i);
            } else {
                mp[nums[i]] = {i};
            }
        }

        unordered_set<vector<int>, VectorHash> sans;
        for(int i = 0; i < n; i++){
            int target = - nums[i];
            for(int j = i+1; j < n; j++){
                if ( mp.find( target - nums[j] ) != mp.end()) {
                    for(int idx : mp[target - nums[j]]) {
                        if (idx > i && idx > j){
                            vector<int> smallAns = {nums[i], nums[j], nums[idx]};
                            sort(smallAns.begin(), smallAns.end());
                            sans.insert(smallAns);
                        }
                    }
                }
            }
        }
        for (vector<int> v : sans){
            ans.push_back(v);
        }
        return ans;
    }
};
