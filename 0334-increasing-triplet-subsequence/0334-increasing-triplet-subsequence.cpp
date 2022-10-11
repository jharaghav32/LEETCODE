class Solution {
public:
    
    bool increasingTriplet(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(ans.back()<nums[i])
                ans.push_back(nums[i]);
            else{
            auto it = lower_bound(ans.begin(),ans.end(),nums[i]);
                ans[it-ans.begin()]=nums[i];
                
            }
        }
        if(ans.size()>=3)return true;
        return false;
    }
};