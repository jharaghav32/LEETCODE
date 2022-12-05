//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    int cuts(int n,int x,int y,int z,vector<int>&dp){
        if(n==0)return 0 ;
        // i have three options eithere to cut the length of size x,y or z
        if(dp[n]!=-1)return dp[n];
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        if(n>=x) 
        a=cuts(n-x,x,y,z,dp); // i have cut the wood of length segment of length x;
        if(n>=y)
        b=cuts(n-y,x,y,z,dp);
        if(n>=z)
        c=cuts(n-z,x,y,z,dp);
        
        return dp[n]=1+max(a,max(b,c));
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
        int ans = cuts(n,x,y,z,dp);
        if(ans<0)return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends