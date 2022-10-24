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
        level.pop_back();// backtracking remove the included element yaha pe ye option nhi bhi rakhe to bhi chalega kyoki actual me jab call kr rhe hai to labhag ye wo wla bhi case cover kr leta jisme ye curr element included nhi hai by using not take recursion call
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>level;
        combination(candidates,target,level,0);
        return ans;
    }
};