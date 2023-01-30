class Solution {
public:
    int tribo(int n){
        if(n==0)return 0;
        if(n==1 || n==2)return 1;
        return tribo(n-1)+tribo(n-2)+tribo(n-3);
    }
    int tribonacci(int n) {
        if(n==0)return 0;
         if(n<3)return 1;
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};