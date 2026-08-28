class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1){
            return s;
        }
        int ans = 0;
        string res;
        for(int i = 0; i < n; i++){
            // odd length
            int l = i, r = i;
            while(l >= 0 && r <= n-1 && s[l] == s[r]){
                if(ans < r - l + 1){
                    ans = r - l + 1;
                    res = s.substr(l, ans);
                }
                l--;
                r++;
            }
            // even length
            l = i, r = i+1;
            while(l >= 0 && r <= n-1 && s[l] == s[r]){
                if(ans < r - l + 1){
                    ans = r - l + 1;
                    res = s.substr(l, ans);
                }
                l--;
                r++;
            }
        }

        return res;
    }
};
