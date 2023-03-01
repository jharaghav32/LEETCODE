class Solution {
public:
    void merge(vector<int>&nums,int l,int m,int r){
        int n = m-l+1;
        int n1 = r-m;
        int left[n];
        int right[n1];
        for(int i=0;i<n;i++){
           left[i]=nums[l+i];
        }
       
        for(int i=0;i<n1;i++){
            right[i]=nums[m+i+1];
        }
        int lft=0;
        int rt=0;
        int i = l;
       while(lft<n && rt<n1){
           if(left[lft]<=right[rt]){
              nums[i++]=left[lft];
               lft++;
           }
           else{
               nums[i++]=right[rt];
               rt++;
           }
       }
        while(lft<n){
            nums[i++]=left[lft++];
        }
        while(rt<n1){
            nums[i++]=right[rt++];
        }
    }
    void mergesort(vector<int>&nums,int l,int r){
        if(l<r){
            int mid = l + (r-l)/2;
            mergesort(nums,l,mid);
            mergesort(nums,mid+1,r);
            merge(nums,l,mid,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
      mergesort(nums,0,nums.size()-1);
        return nums;
    }
};