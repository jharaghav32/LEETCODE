class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini = prices[0];
        int maxi = 0;
        for(int i=1;i<n;i++){
            maxi=max(maxi,prices[i]-mini);// store the profit 
            mini = min(mini,prices[i]);// buying cost 
        }
        return maxi;
    }
};