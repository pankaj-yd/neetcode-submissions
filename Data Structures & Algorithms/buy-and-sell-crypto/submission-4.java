class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;

        int buyPrice = prices[0];
        for (int price : prices) {
            buyPrice = Math.min(buyPrice, price);
            maxProfit = Math.max(maxProfit, price - buyPrice);
        }

        return maxProfit;
    }
}