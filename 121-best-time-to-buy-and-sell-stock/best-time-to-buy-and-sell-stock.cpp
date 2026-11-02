class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int i,j;
        int maxprofit=0;
        for(i=0;i<prices.size();i++)
        {
            mini=min(mini,prices[i]);
           int currprofit=prices[i]-mini;
           maxprofit=max(maxprofit,currprofit);
        }
        
        return maxprofit;
    }
    
};