class Solution {
private:
    int total(vector<int> &coins, int i, int amount, vector<vector<int>> &dp){
        if(i == coins.size() || amount < 0){
            return 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        if(amount == 0){
            return 1; 
        }

        int taken = total(coins, i, amount - coins[i], dp);

        int notTaken = total(coins, i+1, amount, dp);

        dp[i][amount] = taken + notTaken;
        return dp[i][amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        return total(coins, 0, amount, dp);
    }
};
