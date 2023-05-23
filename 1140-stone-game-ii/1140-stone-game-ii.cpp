class Solution {
public:
    int stone(vector<int>&s,int idx,int n,int m,vector<vector<int>>&dp){
        if(idx>=n)return 0;
        if(dp[idx][m]!=-1)return dp[idx][m];
        int ans = INT_MIN;
        int tpick=0;
        for(int i=1;i<=2*m;i++){
            if(idx+i-1<n)tpick+= s[idx+i-1];
            ans = max(ans,tpick-stone(s,idx+i,n,max(m,i),dp));
        }
        return dp[idx][m]= ans;
        
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(101,vector<int>(201,-1));
        int sum=0;
        for(int i=0;i<n;i++){
            sum += piles[i];
           
        }
      int ans =  stone(piles,0,n,1,dp);
        return (ans+sum)/2;
          
    }
};