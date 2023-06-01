class Solution {
public:
    vector<int>dx={0,0,1,-1,-1,1,1,-1};
    vector<int>dy={1,-1,0,0,-1,1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        if(grid[0][0]==0)
        q.push({0,0});
        grid[0][0]=1;
        int ans = INT_MAX;
        int level =0;
        while(!q.empty()){
            int size = q.size();
            // cout<<"my size "<<n<<"\n";
             level +=1;
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                int f = it.first;
                int s = it.second;
                // cout<<f<<" "<<s<<"\n";
                if(f==m-1 && s==n-1){
                    return grid[f][s];
                }
                
                for(int k=0;k<8;k++){
                    int mvx = f + dx[k];
                    int mvy = s + dy[k];
                
                    if(mvx>=0  && mvx<m && mvy>=0 && mvy<n && grid[mvx][mvy]==0 ){
                        q.push({mvx,mvy});
                        grid[mvx][mvy]=grid[f][s]+1;
                    }
                }
            }
           
            
        }
       return -1;
    }
};