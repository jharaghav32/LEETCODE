class Solution {
public:
    void dfs(int src,vector<int>adj[],long long &cnt,vector<int>&vis){
        vis[src]=1;
        cnt++;
        for(auto it : adj[src]){
            if(!vis[it]){
                dfs(it,adj,cnt,vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int  v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans =0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            long long cnt=0;
            if(!vis[i]){
                dfs(i,adj,cnt,vis);
                ans += cnt*(n-cnt);
            }
        }
        return ans/2;
    }
};