class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        deque<int> q;
        int l = 0, r = 0;
        while(r < n){
            while( !q.empty() && nums[q.back()] < nums[r] ){
                q.pop_back();
            }
            q.push_back(r);

            if(r - l + 1 == k) {
                while(q.front() < l){
                    q.pop_front();
                }
                ans.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }

        return ans;
    }
};
