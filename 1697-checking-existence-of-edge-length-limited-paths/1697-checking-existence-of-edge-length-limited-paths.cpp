class Solution {
public:
   static bool cmp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
    vector<int> parent;
vector<int> size;
void make(int node){
    parent[node]=node;
    size[node]=1;
}
int find_set(int node){
    if(parent[node]==node)
    return node;
    return parent[node]=find_set(parent[node]);
}
void Union(int a,int b){
    int x = find_set(a);
    int y = find_set(b);
    // if(size[x]>size[y])
    // swap(x,y);
    parent[x]=y;
    // size[y] += size[x];
}
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        for(int i=0;i<n;i++){
            make(i);
        }
        sort(edgeList.begin(),edgeList.end(),cmp);
        sort(queries.begin(),queries.end(),cmp);
        // for(int i=0;i<queries.size();i++){
        //     for(auto ele : queries[i]){
        //         cout<<ele<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<bool>ans(queries.size());
        int j=0;
        for(int i=0;i<queries.size();i++){
            int limit = queries[i][2];
            while(j<edgeList.size() && edgeList[j][2]<limit ){
                    Union(edgeList[j][0],edgeList[j][1]);
                    j++;
            }
            if(find_set(queries[i][0])==find_set(queries[i][1])){
                ans[queries[i][3]]=true;
            }
            else{
                 ans[queries[i][3]]=false;
            }
        }
       return ans;
    }
};