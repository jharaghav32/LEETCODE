class Solution {
public:
    int mod = 1e9+7;
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].length();
        int t = target.size();
        

        vector<vector<int>> cnt(m, vector<int>(26, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt[j][words[i][j]-'a']++;
            }
        }
        
        vector<vector<int>> dp(t, vector<int>(m, 0));
        
     
        for (int i = 0; i < t; i++) {  
            char c = target[i]-'a';
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = cnt[i][c];
                else if (i == 0)
                    dp[i][j] = dp[i][j-1] + cnt[j][c];
                else if (j == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = (dp[i][j-1] + (long long)dp[i-1][j-1]*cnt[j][c])%mod;
            }
        }
        
        return dp[t-1][m-1];
    }
};