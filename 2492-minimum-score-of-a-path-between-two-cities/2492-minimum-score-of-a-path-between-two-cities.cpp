class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<int>vis(n+1,-1);
        queue<int>q;
        q.push(1);
        int ans = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=1;
            for(auto ele : adj[node]){
                if(vis[ele.first]!=1){
                    ans = min(ans,ele.second);
                    q.push(ele.first);
                }
            }
        }
        return ans;
    }
};