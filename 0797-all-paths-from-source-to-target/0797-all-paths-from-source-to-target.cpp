class Solution {
public:
    vector<int>path;
    void dfs(vector<vector<int>>graph,int src,int dest,vector<vector<int>>&ans){
        path.push_back(src);
        if(src==dest){
            ans.push_back(path);
            
        }
        else{
        for(auto k : graph[src]){
            dfs(graph,k,dest,ans);
        }
        }
        path.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       int dest=graph.size()-1;
        vector<vector<int>>ans;
        dfs(graph,0,dest,ans);
        return ans;
    }
};