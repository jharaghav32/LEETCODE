class Solution {
public:
    vector<int>dx={1,1,1};
    vector<int>dy={-1,0,1};
int Path(vector<vector<int>>&matrix,int m,int n,int i,int j,vector<vector<int>>&dp){
    if(i==m-1){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = INT_MAX;
    for(int k=0;k<3;k++){
      int mvx = i+dx[k];
      int mvy = j+dy[k];
         if(mvx>=0 && mvy>=0 && mvx<m && mvy<n){
         int dist=Path(matrix,m,n,mvx,mvy,dp)+matrix[mvx][mvy];
        ans = min(ans,dist);
         }
       
    }
  return dp[i][j]=ans;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans =INT_MAX;
        for(int i=0;i<n;i++){
           int dist= Path(matrix,m,n,0,i,dp)+matrix[0][i];
            ans = min(ans,dist);
        }
        return ans;
    }
};