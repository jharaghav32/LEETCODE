//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int>dx={1,-1,0,0};
  vector<int>dy={0,0,1,-1};
    void dfs(vector<vector<int>>&grid,int i,int j,vector<pair<int,int>>&vec,int basei,int basej){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)return;
        grid[i][j]=0;
        vec.push_back({
            i-basei,j-basej
        });
        for(int k=0;k<4;k++){
            int mvx = i +dx[k];
            int mvy = j + dy[k];
            dfs(grid,mvx,mvy,vec,basei,basej);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int cnt=0;
        set<vector<pair<int,int>>>st;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>>vec;
                    dfs(grid,i,j,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends