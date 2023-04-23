class Solution {
public:
    int MOD=1e9+7;
    int checknumber(string&s,int idx,int k,int n,vector<int>&dp){
       if(idx>=n)return 1;
        if(s[idx]=='0'){
            //we can't start any number with 0
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        int ways=0;
        long long currNum=0;
        for(int i=idx;i<n;i++){
            currNum = currNum*10 + s[i]-'0';
                if(currNum>k){
                    break;
                }
            ways = (ways + checknumber(s,i+1,k,n,dp))%MOD;
        }
        return dp[idx]=ways;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int>dp(n,-1);
        return checknumber(s,0,k,n,dp);
       
    }
};