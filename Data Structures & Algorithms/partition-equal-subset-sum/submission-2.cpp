class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum % 2 == 1) return false;
        int toMake = sum/2;
        unordered_set<int> uset;
        for(int num : nums){
            for(int ele : uset){
                uset.insert(ele + num);
            }
            uset.insert(num);
        }
        if(uset.find(toMake) != uset.end()){
            return true;
        }
        return false;
    }
};
