class Solution {
public:
      long long points(vector<vector<int>>&questions,int idx,int n,vector<long long>&dp){
           if(idx>=n)return 0;
          if(dp[idx]!=-1)return dp[idx];
           long long a = points(questions,idx+1+questions[idx][1],n,dp)+questions[idx][0];
           long long b = points(questions,idx+1,n,dp);
          return dp[idx]=max(a,b);
       }
    long long mostPoints(vector<vector<int>>& questions) {
      
        int n  = questions.size();
          vector<long long>dp(n,-1);
        return points(questions,0,n,dp);
    }
};