class Solution {
public:
    bool check(vector<int>&a,vector<int>&b){
        for(int i=0;i<26;i++){
            if(a[i]&&b[i])return false;
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans=0;
        vector<vector<int>>v(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(auto c : words[i]){
                v[i][c-'a']=1;
            }
            for(int j=0;j<i;j++){
                if(check(v[i],v[j])){
                    int n1 = words[i].size();
                    int n2 = words[j].size();
                    ans = max(ans,n1*n2);
                }
            }
        }
        return ans;
    }
};