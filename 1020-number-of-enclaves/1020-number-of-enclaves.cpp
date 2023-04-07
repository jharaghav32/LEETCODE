class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    void dfs(int i,int j,vector<vector<int>>&grid,int r,int c){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]!=1)return;
        grid[i][j]=2;
        for(int k=0;k<4;k++){
            int mvx = i+dx[k];
            int mvy= j+dy[k];
            dfs(mvx,mvy,grid,r,c);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        for(int i=0;i<c;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,r,c);
            }
            if(grid[r-1][i]==1){
                dfs(r-1,i,grid,r,c);
            }
        }
        for(int i=0;i<r;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,r,c);
            }
            if(grid[i][c-1]==1){
                dfs(i,c-1,grid,r,c);
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};