class Solution {
public:
    
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second)return a.first<b.first;
        return a.second<b.second;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>v;
        int n = scores.size();
        for(int i=0;i<n;i++){
            v.push_back({scores[i],ages[i]});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>dp(n);
        int ans=0;
         for(int i = 0; i < n; i++) {
            dp[i] = v[i].first;
            for(int j = 0; j < i; j++) {
                if(v[j].first <= v[i].first)
                    dp[i] = max(dp[i], dp[j] + v[i].first);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};