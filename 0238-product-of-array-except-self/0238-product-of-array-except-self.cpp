class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt=0;
        int idx=-1;
        int n = nums.size();
        int product = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            {
                cnt++;
                idx=i;
            } 
            else
                product=product*nums[i];
        }
        vector<int>v;
        if(cnt==1){
          for(int i=0;i<n;i++){
              if(i!=idx){
                  v.push_back(0);
              }
              else
                  v.push_back(product);
          }
        }
            else if(cnt>1){
                for(int i=0;i<n;i++){
                    v.push_back(0);
                }
            }
            else{
                for(int i=0;i<n;i++){
                    v.push_back((product/nums[i]));
                }  
        }
        return v;
    }
};