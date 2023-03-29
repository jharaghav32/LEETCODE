class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        int ans=INT_MIN;
        int neg=0;
        for(int i=0;i<n;i++){
            if(satisfaction[i]<0)neg++;
        }
        if(neg==n)return 0;
        for(int i=0;i<neg || i==0;i++){
            int k=1;
            int currans=0;
            for(int j=i;j<n;j++){
             currans+= satisfaction[j]*(k++);
            }
            ans = max(ans,currans);
        }
        return ans;
    }
};