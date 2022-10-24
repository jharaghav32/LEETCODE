class Solution {
public:
    void subseq(vector<string>&arr,int idx,int currlen,vector<int>vis,int &ans){
        if(idx>=arr.size()){
            ans = max(ans,currlen);
            return;
        }
        vector<int>t=vis;
        bool flag=1;
        for(int i=0;i<arr[idx].size();i++){
            char c = arr[idx][i];
            if(t[c-'a']==1)
            {
                flag=0;
                break;
            }
            t[c-'a']=1;
        }
        if(flag==1)
        subseq(arr,idx+1,currlen+arr[idx].size(),t,ans);
        subseq(arr,idx+1,currlen,vis,ans);
    }
    int maxLength(vector<string>& arr) {
        int ans=0;
        vector<int>vis(26,0);
        subseq(arr,0,0,vis,ans);
        return ans;
    }
};