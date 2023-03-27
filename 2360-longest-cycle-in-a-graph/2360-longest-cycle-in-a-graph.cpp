class Solution {
public:
int ans = INT_MIN;

void dfs(int src, int dist, unordered_map<int, int>& ump,vector<int>&vis,vector<int>adj[]){        
    vis[src] = 1;
    ump[src] = dist;

    for(auto it: adj[src]){
        if(vis[it] == 0){
            dfs(it, dist+1, ump,vis,adj);
        }else if(ump.count(it)){
            ans = max(ans, dist+1 - ump[it] );
        }
    }
}

int longestCycle(vector<int>& edges) {
    int n = edges.size();
   vector<int>adj[n];
   vector<int>vis(n,0);
    for(int i=0; i<n; i++){
        if(edges[i] != -1) 
            adj[i].push_back(edges[i]);
    }

    for(int i=0; i<n; i++){
        unordered_map<int, int> ump; 
        dfs(i, 0, ump,vis,adj);
    }
   if(ans==INT_MIN)return -1;
    return ans;
        }
};