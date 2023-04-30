class Solution
{
public:
       int find(vector<int> &parent,int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node]=find(parent,parent[node]);
    }
    void unions(vector<int> &parent,int u,int v)
    {
        int x=find(parent,u);
        int y=find(parent,v);
        parent[x]=y;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        vector<int> a(n+1),b(n+1);
        int ans=0;
        // initialise each node node as parent of itself
        for(int i=0;i<=n;i++)
        {
            a[i]=i;
            b[i]=i;
        }
        // traversing the edge 
        for(auto &e:edges)
        {
            // menas edges will be traversed by either alice or bob  then continue
            if(e[0]!=3)
                continue;
            //here check if parent of connected nodes is equal or not 
            if(find(a,e[1])==find(a,e[2]))
            {
                ans++;
                continue;
            }
            unions(a,e[1],e[2]);
            unions(b,e[1],e[2]);
        }
        for(auto &e:edges)
        {
            int u=e[1],v=e[2];
            if(e[0]==1)
            {
                if(find(a,u)==find(a,v))
                {
                    ans++;
                }
                else
                {
                    unions(a,u,v);
                }
            }
            else if(e[0]==2)
            {
                if(find(b,u)==find(b,v))
                {
                    ans++;
                }
                else
                {
                    unions(b,u,v);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(find(a,i)!=find(a,n)||find(b,i)!=find(b,n))
            {
                return -1;
            }
        }
        return ans;
        

    }
};
