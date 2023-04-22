class Solution {
public:
    int lcs(string &a,string &b,int n,int m,vector<vector<int>>&dp ){
        if(n==0 || m==0)return dp[n][m]=0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(a[n-1]==b[m-1]){
            return dp[n][m]=lcs(a,b,n-1,m-1,dp)+1;
        }
        else
            return dp[n][m]=max(lcs(a,b,n,m-1,dp),lcs(a,b,n-1,m,dp));
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(501,vector<int>(501,-1));
        string a = s;
         reverse(s.begin(),s.end());

        return n-lcs(a,s,n,n,dp);
    }
};