class Solution {
public:
    int maxProfit(vector<int>& p){
        int prof = 0, minp = p[0];

        for(int price : p){
            if(minp > price){
                minp = price;
            }
            prof = max(prof, price - minp);
        }
        return prof;
    }
};
