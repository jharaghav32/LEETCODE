class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     for(auto ele:nums){
         int idx = abs(ele);
         if(nums[idx]<0)
         return idx;
         nums[idx]=-nums[idx];
     }
     return nums.size();
    }
};