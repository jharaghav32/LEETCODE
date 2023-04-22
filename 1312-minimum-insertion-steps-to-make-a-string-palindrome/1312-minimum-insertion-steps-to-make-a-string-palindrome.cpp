
    class Solution {
public:
    int t[501][501];
    int lcs(string &a,string &b,int m,int n){
        if(m==0 || n==0)
            return t[m][n]=0;
        if(t[m][n]!= -1) return t[m][n];
        if(a[m-1]==b[n-1])
            return t[m][n]=lcs(a,b,m-1,n-1)+1;
        else
            return t[m][n]=max(lcs(a,b,m,n-1),lcs(a,b,m-1,n));
    }
    int minInsertions(string s) {
        memset(t,-1,sizeof(t));
        int m = s.length();
        string rev;
        for(int i=m-1;i>=0;i--)
            rev.push_back(s[i]);
        return m-lcs(s,rev,m,m);
    }
};
  
