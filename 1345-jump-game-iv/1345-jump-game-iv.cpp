class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>ump;
        int n = arr.size();
        if(n==1)return 0;
        if(arr[0]==arr[n-1])return 1;
        for(int i=0;i<n;i++){
            ump[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        int level=0;
        while(!q.empty()){
            // cout<<n<<" ";
            int size = q.size();
            for(int i=0;i<size;i++){
          int idx = q.front();
            q.pop();
            if(idx==n-1)return level;
            if(!vis[idx]){
                if(idx!=0 && vis[idx-1]==0){
                    q.push(idx-1);
                }
                if(idx!=n-1 && vis[idx+1]==0){
                    q.push(idx+1);
                }
                for(auto ele:ump[arr[idx]]){
                    if(ele!=idx && vis[ele]==0){
                        q.push(ele);
                    }
                }
                ump[arr[idx]].clear();
                vis[idx]=1;
            }
            }
            level++;
        }
        return level;
    }
};