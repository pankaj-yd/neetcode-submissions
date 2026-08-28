bool checkAnagram(string s, string t) {
    sort(t.begin(), t.end());
    return s.compare(t) == 0;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> mp;
        unordered_map<string, vector<string>> ans;
        for (string s : strs){
            int n = s.size();
            if( mp.find(n) != mp.end() ) {
                // do
                vector<string> sameSizeStrs = mp[n];
                bool foundAna = false;
                for (string str : sameSizeStrs) {
                    // check if anagram
                    if (checkAnagram(str, s)) {
                        ans[str].push_back(s);
                        foundAna = true;
                    }
                }
                if(foundAna == false) {
                    string t = s;
                    sort(t.begin(), t.end());
                    ans[t].push_back(s);
                    mp[n].push_back(t);
                }
            }
            else {
                string t = s;
                sort(t.begin(), t.end());
                ans[t].push_back(s);
                mp[n].push_back(t);
            }
        }
        vector<vector<string>> ansStr;
        for (auto it = ans.begin(); it != ans.end(); it++){
            ansStr.push_back(it->second);
        }
        return ansStr;
    }
};
