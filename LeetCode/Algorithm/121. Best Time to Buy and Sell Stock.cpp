class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        if(prices.size() == 0)
            return 0;
        
        for(int i = 0; i < prices.size() - 1; i++)
        {
            int tempProfit = 0;
            for(int j = i + 1; j < prices.size();j++)
            {
                tempProfit += prices[j] - prices[j-1];
                if(tempProfit > maxProfit)
                    maxProfit = tempProfit;
                if(tempProfit <= 0)
                    break;
            }
        }
        
        return maxProfit;
    }
};