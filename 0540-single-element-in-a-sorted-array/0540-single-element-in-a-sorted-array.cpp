class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i>0){
            if(nums[i]==nums[i-1])i=i-2;
            else return nums[i];
        }
        return nums[0];
    }
};