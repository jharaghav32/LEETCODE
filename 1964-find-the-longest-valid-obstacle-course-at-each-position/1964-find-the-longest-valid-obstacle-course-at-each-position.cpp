class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
       int n = obstacles.size();
         vector<int> dp (n,1);
        vector<int> b(n+1, INT_MAX);
        b[0]=INT_MIN;
       
        for(int i=0; i<obstacles.size(); i++){
            auto k = upper_bound(b.begin(), b.end(), obstacles[i]) - b.begin();
            b[k] = obstacles[i];
            dp[i]=k;
        }
        return dp;
    }
};