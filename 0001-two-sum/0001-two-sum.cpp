class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          vector<int> ans;
              unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end())
            {
                if(i!=mp[target-nums[i]]){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                break;
                }
            }
            
        }
        return ans;
    }
};