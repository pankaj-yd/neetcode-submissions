class Solution {
private:
    int calc(vector<int>& coins, int amount, int idx){
        if(amount == 0){
            return 0;
        }
        if(amount < 0 || idx >= coins.size()){
            return -1;
        }
        int val = coins[idx];
        int cost1 = calc(coins, amount-val, idx);
        int cost2 = calc(coins, amount, idx + 1);
        if(cost1 == -1 && cost1 == cost2){
            return -1;
        } else if(cost2 == -1){
            cost1 += 1;
            return cost1;
        } else if(cost1 == -1){
            return cost2;
        } else {
            cost1 += 1;
            return min(cost1, cost2);
        }
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        int n = coins.size();
        int coin = 0;
        return calc(coins, amount, 0);;
    }
};
