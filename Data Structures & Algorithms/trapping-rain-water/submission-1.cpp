class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        int l = 0, r = n-1;
        int lm = h[l], rm = h[r];
        int ans = 0;
        while(l <= r){
            if (lm < rm) {
                lm = max(lm, h[l]);
                ans += lm - h[l];
                l++;
            } else {
                rm = max(rm, h[r]);
                ans += rm - h[r];
                r--;
            }
        }
        return ans;
    }
};
