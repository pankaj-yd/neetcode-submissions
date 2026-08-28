class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num: nums) {
            s.insert(num);
        }

        if (s.size () == nums.size()) return false;
        return true;
    }

};
