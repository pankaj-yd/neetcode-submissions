class Solution {
public:
    int change(int amount, vector<int>& coins){
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int coin : coins){
            vector<int> newdp(amount+1, 0);
            for(int amt = 0; amt <= amount; amt++){
                // newdp[amt] = dp[amt];
                if(coin <= amt){
                    dp[amt] += dp[amt - coin];
                }
            }
            // dp = newdp;
        }

        return dp[amount];
    }
};
