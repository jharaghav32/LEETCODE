class Solution {
public:
    vector<vector<int>>ans;
    void subsets(vector<int>&nums,int idx,int n,vector<int>level){
        if(idx>=n){
            ans.push_back(level);
            return;
        }
        subsets(nums,idx+1,n,level);// not take that element 
        level.push_back(nums[idx]);// iclude the element in level vector 
        subsets(nums,idx+1,n,level);// call after taking that element
    
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>level;
        subsets(nums,0,nums.size(),level);
        return ans;
    }
};