class Solution {
public:
    stack<int>st;
    bool cycle=false;
    void dfs(int node,vector<int>&visited,vector<int>&pathvisited,vector<int>adj[]){
        visited[node]=1;
        pathvisited[node]=1;
        for(auto it : adj[node]){
            if(visited[it] && pathvisited[it]){
                cycle=true;
            }
            if(!visited[it]){
                dfs(it,visited,pathvisited,adj);
            }
        }
        pathvisited[node]=0;
        st.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
         adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>visited(numCourses,0);
        vector<int>pathvisited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(i,visited,pathvisited,adj);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        if(ans.size()!=numCourses || cycle)return {};
        else return ans;
    }
};