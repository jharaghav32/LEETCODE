class Solution {
public:
    int findtarget(vector<int>&nums,int idx,int sum,int target,vector<unordered_map<int,int>>&dp){
        if(sum==target && idx==nums.size())return 1;
        if(idx>=nums.size())return 0;
        auto it = dp[idx].find(sum);
        if(it != dp[idx].end()) return it->second;
return dp[idx][sum]=findtarget(nums,idx+1,sum+nums[idx],target,dp)+findtarget(nums,idx+1,sum-nums[idx],target,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>>dp(nums.size());
        return findtarget(nums,0,0,target,dp);
    }
};