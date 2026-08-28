class Solution {
private:
    int count(int amt, vector<int>& coins, unordered_map<int, int> &umap){
        if(amt < 0) return INT_MAX;

        if( umap.find(amt) != umap.end() ) return umap[amt];

        
        int ncoin = INT_MAX;
        for(int coin : coins){
            if(coin <= amt){
                ncoin = min(ncoin - 1, count(amt - coin, coins, umap));
                if(ncoin != INT_MAX) ncoin++;
            }
        }

        umap[amt] = ncoin;
        return ncoin;
    }
public:
    int coinChange(vector<int>& coins, int amount){
        unordered_map<int, int> umap;
        umap[0] = 0;
        count(amount, coins, umap);
        return umap[amount] == INT_MAX? -1 : umap[amount];
    }
};
