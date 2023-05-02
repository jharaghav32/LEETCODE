class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool zero=false;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero=true;
                break;
            }
            else if(nums[i]<0){
                cnt++;
            }
        }
        if(zero)return 0;
        if(cnt%2==0)return 1;
        return -1;
        
    }
};