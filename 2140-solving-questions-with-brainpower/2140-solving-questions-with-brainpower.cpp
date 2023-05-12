class Solution {
public:
     
    long long mostPoints(vector<vector<int>>& questions) {
      
        int n  = questions.size();
          vector<long long>dp(200001,0);// here we create a size of 2 * 1e5 because the max index we may reach is this so to avoid rte we do this and initialise it to zero
        for(int i=n-1;i>=0;i--){
         dp[i]=max(dp[i+1+questions[i][1]]+questions[i][0],dp[i+1]);
        }
        return dp[0];
    }
};