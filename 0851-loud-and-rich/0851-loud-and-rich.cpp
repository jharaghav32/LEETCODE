class Solution {
public:
    unordered_map<int,int>ump;
    
    int  dfs(int node,vector<int>&vis,vector<int>&ans,vector<int>&quiet,vector<int>adj[]){
        vis[node]=1;
        int mini = quiet[node];
        for(auto it : adj[node]){
            if(!vis[it]){
               int miniele = dfs(it,vis,ans,quiet,adj);
                mini=min(mini,miniele);
            }
            else{
                mini = min(mini,quiet[ans[it]]);
            }
        }
        ans[node]=ump[mini];
      
        return mini;
         
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int>adj[n];
        for(int i=0;i<richer.size();i++){
            int u = richer[i][1];
            int v = richer[i][0];
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
           ump[quiet[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,ans,quiet,adj);
            }
        }
        return ans;
    }
};