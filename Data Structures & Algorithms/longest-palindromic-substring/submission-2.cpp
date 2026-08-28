class Solution {
public:
    string longestPalindrome(string s){
        int n = s.size();

        if(n == 1) return s;

        string ans = "";
        for(int i = 0; i < n; i++){
            // odd length with midpoint s[i]
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                    l--;
                    r++;
            }

            if(ans.size() < r - l - 1){
                ans = s.substr(l+1, r - l - 1);
            }

            // even length with midpoint s[i], s[i+1]
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                l--;
                r++;
            }

            if(ans.size() < r - l - 1){
                ans = s.substr(l+1, r - l - 1);
            }
        }

        return ans;
    }
};
