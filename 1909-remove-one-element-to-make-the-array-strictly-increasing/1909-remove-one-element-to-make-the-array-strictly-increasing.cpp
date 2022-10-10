class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return true;
        int prev=nums[0];
        bool one=false;
        for(int i=1;i<n;i++){
         if(nums[i]<=prev){
             if(one)return false;
             one=true;
         }
        if(i!=1 && nums[i-2]>=nums[i]){
            prev=prev;
             }
            else
         prev=nums[i]; 
        }
        return true;
    }
};