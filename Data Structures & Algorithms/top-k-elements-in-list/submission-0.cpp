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
        vector<pair<int,int>> freq;
        for(auto it = count.begin(); it != count.end(); it++){
            freq.push_back({it->second, it->first});
        }
        sort(freq.begin(), freq.end(), comp);

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};
