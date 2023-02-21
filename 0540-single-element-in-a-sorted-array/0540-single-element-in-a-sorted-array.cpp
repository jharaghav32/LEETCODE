class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int j = n-1;
        int i=0;
        while(i<j){
            int mid = (i+j)/2;
            if(mid%2==0 && nums[mid]==nums[mid+1]){
                i = mid+2;
            }
            else if(mid%2!=0 && nums[mid]==nums[mid-1]){
                i = mid+1;
            }
            else{
                j= mid-1;
            }
        }
        return nums[i];
        
    }
};