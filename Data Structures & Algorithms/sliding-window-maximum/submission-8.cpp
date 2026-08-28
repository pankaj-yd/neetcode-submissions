class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        vector<int> ans;
        deque<int> idx;
        int j = 0;
        while(j < k){
            while(idx.size() > 0 && nums[idx.back()] < nums[j]){
                idx.pop_back();
            }
            idx.push_back(j);
            j++;
        }

        ans.push_back(nums[idx.front()]);
        while(j < nums.size()){
            while(idx.size() > 0 && nums[idx.back()] < nums[j]){
                idx.pop_back();
            }
            idx.push_back(j);

            while(idx.size() > 0 && j - idx.front() >= k){
                idx.pop_front();
            }

            ans.push_back(nums[idx.front()]);

            j++;
        }


        return ans;
    }
};
