class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>vis(2001,0);
        for(int i=0;i<n;i++){
            vis[arr[i]]++;
        }
        for(int i=1;i<=2000;i++){
            if(vis[i]==0){
                k--;
            }
            if(k==0)return i;
        }
        return 1000;
    }
};