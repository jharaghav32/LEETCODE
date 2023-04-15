class Solution {
public:
   
    int coins(vector<vector<int>>&piles,int i,int k,int n,vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
       
        int ans =0;
        ans = max(ans,coins(piles,i+1,k,n,dp));
        for(int x=0;x<piles[i].size();x++){
            if(x+1<=k)
            ans= max(ans,coins(piles,i+1,k-x-1,n,dp)+piles[i][x]);
            else
            {
                break;
            }
        }
        return dp[i][k]= ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        for(int i=0;i<n;i++){
          
            for(int j=1;j<piles[i].size();j++){
               piles[i][j]=piles[i][j]+piles[i][j-1];
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return coins(piles,0,k,n,dp);
        
    }
};