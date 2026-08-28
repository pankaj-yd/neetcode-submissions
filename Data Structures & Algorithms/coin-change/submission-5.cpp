class Solution {
private:
    int calc(vector<int>& coins, int amount, unordered_map<int, int> &dp){
        if(amount < 0){
            return INT_MAX;
        }
        if(dp.find(amount) != dp.end()){
            cout << "Using dp amount: " << amount << endl;
            return dp[amount];
        }
        cout << amount << "->" << " ";
        int minSteps = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int steps = calc(coins, amount - coins[i], dp);
            if(steps == INT_MAX){
                continue;
            } else {
                minSteps = min(minSteps, 1 + steps);
            }
        }
        dp[amount] = minSteps;
        cout << "\n";
        return minSteps;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int> dp;
        
        dp[0] = 0;
        int steps = calc(coins, amount, dp);
        return steps == INT_MAX? -1 : steps;
        
    }
};
