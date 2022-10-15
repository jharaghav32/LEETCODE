class Solution {
public:
    // I have to move on this problem again didn't understand properly 
    int dp[101][101];
        int compress(string &s, int left, int K) {
        int k = K;
        if(s.size() - left <= k) return 0;
        if(dp[left][k] >= 0) return dp[left][k];
        int res = k ? compress(s, left + 1, k - 1) : 10000, c = 1;
        for(int i = left + 1; i <= s.size(); ++i) {
            res = min(res, compress(s, i, k) + 1 + (c >= 100 ? 3 : (c >= 10 ? 2 : (c > 1 ? 1 :0))));
            if(i == s.size()) break;
            if(s[i] == s[left]) ++c;
            else if(--k < 0) break;
        }
        return dp[left][K] = res;
    }

    int getLengthOfOptimalCompression(string s, int k) {
                memset(dp, -1, sizeof(dp));
        return compress(s, 0, k);

    }
};