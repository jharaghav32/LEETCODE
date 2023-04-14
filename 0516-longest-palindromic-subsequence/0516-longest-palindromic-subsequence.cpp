class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>v(n+1,vector<int>(n+1,0));
        string rev ;
        for(int i=n-1;i>=0;i--)
      rev.push_back(s[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==rev[j-1]){
                    v[i][j]=v[i-1][j-1]+1;
                }
                else{
                    v[i][j]=max(v[i-1][j],v[i][j-1]);
                }
            }
        }
        return v[n][n];
        
    }
};