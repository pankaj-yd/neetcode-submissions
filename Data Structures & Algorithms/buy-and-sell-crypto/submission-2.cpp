class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int l = 0, r = l+1;

        int ans = 0;
        while(r < n){
            if (p[l] < p[r]){
                ans = max(ans, p[r] - p[l]);

            } else{
                l = r;
                
            }
            r++;
        }
        return ans;
    }
};
