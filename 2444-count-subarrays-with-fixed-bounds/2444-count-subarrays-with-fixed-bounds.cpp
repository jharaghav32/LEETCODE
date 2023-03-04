class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int startIdx=0;
        int minStartIdx=0;
        int maxStartIdx=0;
        bool minPres=false;//it check whether the element with minK value is found or not
        bool maxPres=false;//It check whether the element with value maxK is founded or not
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK)//means element is not in the range of minK and maxK
            {
             minPres=false;
             maxPres=false;
                startIdx=i+1;
                //because we can't this element in our subarray and if this element is present in any of our subarray then it doesn't satisfy the condition so don't take this element and now start from next element and mark all the element with minK and maxK as false as we have to start again
            }
            
            if(nums[i]==minK){
                minPres=true;
                minStartIdx=i;
            }
            if(nums[i]==maxK){
                maxPres=true;
                maxStartIdx=i;
            }
            if(maxPres && minPres){
                ans += 1 + (min(maxStartIdx,minStartIdx)-startIdx);//this will calculate the no of element before minidx of maxvalue and minvalue which is in the range so we include that element also in our subarray and add 1 as the subarray form minstartidx and maxstartidx
            }
        }
        return ans;
    }
};