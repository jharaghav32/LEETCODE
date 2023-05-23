class Solution {
public:
    int stone(vector<int>&s,int idx,int n,vector<int>&dp){
        if(idx>=n)return 0;
        int ans = INT_MIN;
        if(dp[idx]!=-1)return dp[idx];
        ans = max(ans,s[idx]-stone(s,idx+1,n,dp));
        if(idx+1<n)
            ans = max(ans,s[idx]+s[idx+1]-stone(s,idx+2,n,dp));
        if(idx+2<n)
            ans = max(ans,s[idx]+s[idx+1]+s[idx+2]-stone(s,idx+3,n,dp));
        
        return dp[idx]= ans;
        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n+1,-1);
        int ans = stone(stoneValue,0,stoneValue.size(),dp);
        if(ans>0)return "Alice";
        else if(ans<0)return "Bob";
        return "Tie";
    }
};