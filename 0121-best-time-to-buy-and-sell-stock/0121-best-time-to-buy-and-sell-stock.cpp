class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = 0;
        int min_prices = prices[0];

        for(int i = 0; i < prices.size(); i++) {
            maxprof = max(maxprof, prices[i] - min_prices);
            min_prices = min(prices[i], min_prices);
        }
        return maxprof;
    }
};