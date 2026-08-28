bool comp(pair<int,int> s, pair<int,int> t){
    return s.first > t.first;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num : nums){
            count[num] += 1;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for(auto it = count.begin(); it != count.end(); it++){
            buckets[it->second].push_back(it->first);
        }
        

        vector<int> ans;
        for (int i = buckets.size() -1 ; i >= 0 ; i--){
            for ( int n : buckets[i]) {
                ans.push_back(n);
                if (ans.size() == k) return ans;
            }
        }
    }
};
