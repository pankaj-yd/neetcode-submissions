class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> present(128, false);
        int n = s.size();
        if(n == 1) return 1;
        
        int l = 0, r = l;
        int ans = 0;
        while(r < n){
            if (present[s[r]]){
                ans = max(ans, r - l);

                while(present[s[r]]){
                    present[s[l]] = false;
                    l++;
                }
            }
            present[s[r]] = true;
            r++;
        }
        ans = max(ans, r-l);
        return ans;
    }
};
