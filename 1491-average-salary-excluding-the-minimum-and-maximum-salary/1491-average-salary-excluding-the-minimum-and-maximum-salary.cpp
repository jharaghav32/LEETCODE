class Solution {
public:
    double average(vector<int>& salary) {
        int sum=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;
       for(int i=0;i<salary.size();i++){
           sum+=salary[i];
           maxi = max(maxi,salary[i]);
           mini=min(mini,salary[i]);
       } 
        sum = sum-(maxi+mini);
        
        int n = salary.size()-2;
        double ans = (double)sum/n;
        return ans;
    }
};