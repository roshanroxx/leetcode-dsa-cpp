class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int p =0;
        for(int i=1;i<prices.size();i++){
            p = max(prices[i]-min,p);
            if(prices[i]<min){min = prices[i];}
        }
        return p;
    }
};