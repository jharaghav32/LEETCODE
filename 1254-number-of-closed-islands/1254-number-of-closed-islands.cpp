class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,-1,1};
    bool dfs(int i,int j,vector<vector<int>>&grid,int r,int c){
      
        if(i<0 || j<0 || i>=r || j>=c)return false;
        if(grid[i][j]==1)return true;
          grid[i][j]=1;
        bool flag=true;
        for(int k=0;k<4;k++){
            int mvx = i+dx[k];
            int mvy=j+dy[k];
            if(!dfs(mvx,mvy,grid,r,c)){
                flag=false;
            }               
            
        }
        return flag;
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    if(dfs(i,j,grid,r,c)){
                        ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};