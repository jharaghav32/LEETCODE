class Solution {
public:
    int ans=0;
    void dfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        ans++;
        
        for(auto it :adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
        
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adj[n];
        vector<int>ump(n,0);
        for(int i=0;i<restricted.size();i++){
            ump[restricted[i]]++;
        }
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(ump[u]!=1 && ump[v]!=1){
            adj[u].push_back(v);
            adj[v].push_back(u);
            }
          
        }
        vector<int>vis(n);
        dfs(0,vis,adj);
        return ans;
        
    }
};