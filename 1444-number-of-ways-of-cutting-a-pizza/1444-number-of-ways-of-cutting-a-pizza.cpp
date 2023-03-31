class Solution {
public:
    int MOD = 1e9+7;
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].size();
        vector<vector<int>> count(rows + 1, vector<int>(cols + 1));
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                count[i][j] = count[i + 1][j] + count[i][j + 1] - count[i + 1][j + 1] + (pizza[i][j] == 'A');
            }
        }
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k + 1)));
        for (int p = 1; p <= k; p++) {
            for (int i = rows - 1; i >= 0; i--) {
                for (int j = cols - 1; j >= 0; j--) {
                    if (p == 1) {
                        dp[i][j][p] = (count[i][j] > 0);
                    } else {
                        int ways = 0;
                        for (int q = i + 1; q < rows; q++) {
                            if (count[i][j] - count[q][j] > 0) {
                                ways = (ways + dp[q][j][p-1]) % MOD;
                            }
                        }
                        for (int q = j + 1; q < cols; q++) {
                            if (count[i][j] - count[i][q] > 0) {
                                ways = (ways + dp[i][q][p-1]) % MOD;
                            }
                        }
                        dp[i][j][p] = ways;
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};