//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int m =matrix.size();
        int n =matrix[0].size();
        int top=0;
        int down =m-1;
        int left=0;
        int rt=n-1;
        bool ltr,ttd,rtl;
        vector<int> ans;
        ltr=true;
        ttd=false;
        rtl=false;
        while(top<=down && left<=rt){
            if(ltr){
                for(int i=left;i<=rt;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
                ttd=true;
                ltr=false;
            }
            else if(ttd){
                for(int i=top;i<=down;i++){
                    ans.push_back(matrix[i][rt]);
                }
                rt--;
                ttd=false;
                rtl=true;
                
            }
            else if(rtl){
                for(int i=rt;i>=left;i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
                rtl=false;
            }
            else{
                for(int i=down;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                ltr=true;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends