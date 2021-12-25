## https://leetcode.com/problems/best-time-to-buy-and-sell-stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsf = prices[0];
        int maxp = 0;
        for(int i=1;i<prices.size();i++){
            minsf = min(minsf,prices[i]);
            int profit = prices[i] - minsf;
            maxp = max(profit,maxp);
        }
        return maxp;
    }
};