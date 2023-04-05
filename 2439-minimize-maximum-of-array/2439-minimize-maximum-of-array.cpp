class Solution {
public:
    bool Valid(int optimal ,vector<int>&nums){
        long long extra =0;
        for(int i=0;i<nums.size();i++){
            if(optimal <nums[i]){
                long long val = nums[i]-optimal;
                if(extra<val)return false;
                extra = extra - val;
            }
            else{
                long long val = optimal - nums[i];
                extra = extra + val;
            }
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
       int n = nums.size();
        int mini=INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        int ans=nums[0];
        while(mini<=maxi){
            int mid = (mini+maxi)/2;
            if(Valid(mid,nums)){
                maxi = mid-1;
                ans=mid;
            }
            else{
                mini=mid+1;
            }
        }
        return ans;
      
    }
};