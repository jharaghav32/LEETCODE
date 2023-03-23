class Solution {
public:
    void dfs(int node,vector<int>&vis ,vector<int>adj[]){
        vis[node]=1;
        for(auto i: adj[node]){
            if(vis[i]==0){
                dfs(i,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(connections.size()<n-1)
            return -1;
        vector<int>vis(n+1,0);
        
        vector<int>adj[n+1];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,adj);
                comp++;
            }
        }
        int redundant = edges - ((n-1)-(comp-1));
        if(redundant>=(comp-1))
            return comp-1;
        else
            return -1;
    }
};