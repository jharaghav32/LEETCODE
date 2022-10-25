class Solution {
public:
    int findtarget(vector<int>&nums,int idx,int sum,int target){
        if(sum==target && idx==nums.size())return 1;
        if(idx>=nums.size())return 0;
        return findtarget(nums,idx+1,sum+nums[idx],target)+findtarget(nums,idx+1,sum-nums[idx],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return findtarget(nums,0,0,target);
    }
};