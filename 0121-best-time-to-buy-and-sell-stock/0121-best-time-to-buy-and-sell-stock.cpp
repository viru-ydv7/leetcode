class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minatleft=prices[0];
        int i=1;
        for(i;i<prices.size();i++){
            int profit=prices[i]-minatleft;
            maxProfit=max(profit,maxProfit);
            minatleft=min(minatleft,prices[i]);
        }
        return maxProfit;
    }
};