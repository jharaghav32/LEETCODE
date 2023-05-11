class Solution {
public:
    int uncrossed(vector<int>&nums1,vector<int>&nums2,int m,int n,vector<vector<int>>&dp){
        if(m<=0 || n<=0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        int a =INT_MIN;
        a = max(a,max(uncrossed(nums1,nums2,m-1,n,dp),uncrossed(nums1,nums2,m,n-1,dp)));
        if(nums1[m-1]==nums2[n-1]){
            a = max(a,uncrossed(nums1,nums2,m-1,n-1,dp)+1);
        }
        return dp[m][n]= a ;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return uncrossed(nums1,nums2,m,n,dp);
    }
};