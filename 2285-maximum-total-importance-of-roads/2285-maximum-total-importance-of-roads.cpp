class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        vector<int>indeg(n,0);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            indeg[u]++;
            indeg[v]++;
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({indeg[i],i});
        }
        vector<int>val(n);
        int elem = n;
        while(!pq.empty()){
            auto it  = pq.top();
            pq.pop();
            val[it.second]=elem;
            elem--;
        }
        
        for(int i=0;i<roads.size();i++){
              int u = roads[i][0];
            int v = roads[i][1];
            ans += val[u]+val[v];
            
        }
        return ans;
    }
};