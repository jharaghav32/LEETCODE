class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int outrange=-1;
        int minidx=-1;
        int maxidx=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                outrange=i;
            }
            if(nums[i]==minK){
                minidx=i;
            }
            if(nums[i]==maxK){
                maxidx=i;
            }
            ans+= max(0,min(minidx,maxidx)-outrange);
            
        }
        return ans;
    }
};