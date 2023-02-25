class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n= nums.size();
        vector<int>maxl(n);
        vector<int>minr(n);
        for(int i=0;i<n;i++){
            if(i==0){
                maxl[i]=nums[i];
            }
            else{
                maxl[i]=max(maxl[i-1],nums[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                minr[i]=nums[i];
            }
            else{
                minr[i]=min(minr[i+1],nums[i]);
            }
        }
        int ans=0;
        for(int i=1;i<=n-2;i++){
            if(nums[i]>maxl[i-1] && nums[i]<minr[i+1])
                ans+=2;
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1])
                ans+=1;
        }
        return ans;
        
    }
};