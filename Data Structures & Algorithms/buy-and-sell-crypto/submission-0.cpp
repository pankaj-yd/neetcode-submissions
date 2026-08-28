class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> mp(n, 0);
        mp[n-1] = p[n-1];
        for(int i = n-2; i >= 0; i--){
            mp[i] = max(p[i], mp[i+1]);
        }

        int profit = 0;
        for(int i = 0; i < n; i++){
            profit = max(profit, mp[i] - p[i]);
        }

        return profit;
    }
};
