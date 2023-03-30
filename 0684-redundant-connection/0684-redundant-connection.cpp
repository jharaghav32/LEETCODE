class Solution {
public:
    vector<int>parent;
    vector<int>size;
    void make_set(int node){
        parent[node]=node;
        size[node]=1;
    }
    int find_set(int node){
        if(parent[node]==node)return node;
        return find_set(parent[node]);
    }
    void Union(int x,int y){
    int u = find_set(x);
    int v  = find_set(y);
    if(size[u]>size[v])
        swap(u,v);
    parent[u]=v;
    size[u] += size[v];
    
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++){
       make_set(i);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int u = find_set(x);
            int v = find_set(y);
            if(u==v){
                ans.push_back({x,y});
            }
            Union(u,v);
        }
        return ans.back();
    }
};