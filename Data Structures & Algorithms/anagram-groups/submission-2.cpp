class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            vector<int> charMapping(26, 0);
            for (char c : s) {
                charMapping[c - 'a'] += 1;
            }
            string key;
            for (int i : charMapping) {
                key += "#" + to_string(i);
            }
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
