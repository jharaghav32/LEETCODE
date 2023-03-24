class Solution {
public:
    int cnt=0;
    set<pair<int,int>>st;
    void dfs(int src,vector<int>adj[],vector<int>&vis){
        vis[src]=1;
        for(auto it : adj[src]){
            if(!vis[it]){
              if(st.find({src,it})!=st.end()){
                  cnt++;
              }
                dfs(it,adj,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>vis(n,0);
        
        vector<int>adj[n];
        for(int i=0;i<connections.size();i++){
            st.insert({connections[i][0],connections[i][1]});
            adj[connections[i][0]].push_back(connections[i][1]);
             adj[connections[i][1]].push_back(connections[i][0]);
        }
        
                 dfs(0,adj,vis);
        
       
        return cnt;
        
    }
};