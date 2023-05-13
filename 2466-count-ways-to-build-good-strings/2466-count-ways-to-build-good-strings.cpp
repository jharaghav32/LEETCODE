class Solution {
public:
    int Mod = 1e9+7;
   int  count(int one,int zero,int target,vector<int>&dp){
      if(target==0)return 1;
       if(target<0)return 0;
       if(dp[target]!=-1)return dp[target];
       return dp[target]=(count(one,zero,target-one,dp)%Mod+count(one,zero,target-zero,dp)%Mod)%Mod;
   }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans =0;
        vector<int>dp(high+1,-1);
        for(int i=low;i<=high;i++){
             ans  = (ans+count(one,zero,i,dp))%Mod;
        }
        return ans%Mod;
        
    }
};