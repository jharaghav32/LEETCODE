class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int q = queries.size();
        
        vector<int>ans;
        for(int i=0;i<q;i++){
            int csum=0;
            int lgsize=0;
            for(int j=0;j<n;j++){
                if(csum + nums[j]<=queries[i])
                {   lgsize++;
                 csum += nums[j];
                }
            }
            ans.push_back(lgsize);
        }
        return ans;
    }
};