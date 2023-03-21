class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<long long>cnt;
        long long count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
                
            }
            else{
                if(count){
                    cnt.push_back(count);
                    count=0;
                }
            }
        }
        if(count)cnt.push_back(count);
        
        long long sum=0;
        for(int i=0;i<cnt.size();i++){
            long long subarr = (cnt[i]*(cnt[i]+1))/2;
            sum += subarr;
        }
        return sum;
    }
};