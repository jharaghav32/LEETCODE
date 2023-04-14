class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        string rev ;
        for(int i=n-1;i>=0;i--)
      rev.push_back(s[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==rev[j-1]){
                    curr[j]=prev[j-1]+1;
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return curr[n];
     //  the time complexity is O(n*n)
        //space complexity is O(n)
    }
};