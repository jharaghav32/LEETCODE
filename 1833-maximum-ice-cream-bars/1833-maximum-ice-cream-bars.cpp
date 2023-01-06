class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // actually if we want to buy maximum icecreams so we will buy icecream bars of 
        // whose costs is minimum so sort the costs
        sort(costs.begin(),costs.end());
        int ans=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                ans+=1;
                coins = coins-costs[i];
            }
            
        }
        return ans;
    }
};