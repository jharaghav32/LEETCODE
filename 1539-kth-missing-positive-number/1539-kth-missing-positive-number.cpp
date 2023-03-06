class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int len = arr[n-1];
        int missingNumber=len-n;
        if(missingNumber>=k){
          vector<int>vis(len+1,0);
            for(int i=0;i<n;i++){
             vis[arr[i]]++;
            }
            for(int i=1;i<=len;i++){
                if(vis[i]==0){
                    k--;
                }
                if(k==0)return i;
            }
            return len;
        }
        else{
            return (k-missingNumber)+len;
        }
    }
};