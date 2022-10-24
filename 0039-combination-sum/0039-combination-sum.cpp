class Solution {
public:
    vector<vector<int>>ans;
    void combination(vector<int>&candidates,int sum,vector<int>level,int idx){
        if(sum==0){
            ans.push_back(level);
            return;
        }
        if(idx>=candidates.size() || sum<0 )
            return;
        combination(candidates,sum,level,idx+1);
        level.push_back(candidates[idx]);// include the element to take that element 
        combination(candidates,sum-candidates[idx],level,idx);
        level.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>level;
        combination(candidates,target,level,0);
        return ans;
    }
};