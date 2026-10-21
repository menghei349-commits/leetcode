class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ans = 0;
        int buy = prices[0] + fee;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] + fee < buy) {
                buy = prices[i] + fee;
            } else if (prices[i] > buy) {
                ans += prices[i] - buy;
                buy = prices[i];
            }
        }
        return ans;
    }
};