class Solution {
public:
    void sortColors(vector<int>& nums) {
        //DUTCH NATIONAL FLAG ALGORITHM
        // which states that from left to low the element is 0 and from high to right element the element is 2;
        
        int n = nums.size();
        int low=0;//here we creates three pointer low and mid points to zero
        // and high points to last element 
        int mid=0;
        // whenever the element at mid is equal to zero replace it with low and increment both 
        // if the element at mid is 2 swap with high and decrement high
        // and in last case simply increment mid
        int high=n-1;
            while(mid<=high){
                if(nums[mid]==0){
                    swap(nums[mid],nums[low]);
                    mid++;
                    low++;
                }
                else if(nums[mid]==2){
                    swap(nums[mid],nums[high]);
                    high--;
                }
                else{
                    mid++;
                }
            }
        
    }
};