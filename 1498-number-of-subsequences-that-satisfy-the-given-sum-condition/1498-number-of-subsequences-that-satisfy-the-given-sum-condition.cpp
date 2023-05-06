class Solution {
public:
    int ans=0;
    const int Mod = 1e9+7;
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        int i=0;
        int j=n-1;
        vector<int>pow(n+1,1);
        for(int k=1;k<=n;k++)
        {
            pow[k]=(2*pow[k-1])%Mod;
        }
        while(i<=j)
        {
            if(nums[j]+nums[i]<=target)
            {
                ans=(ans+pow[j-i])%Mod;
                i++;
            }
            else
                j--;
        }
        return ans;
    }
};