class Solution {
public:
    int count(int mid,int m,int n){
        int cnt=0;
        for(int i=1;i<=m;i++){
          int  temp = min(mid/i,n);
            cnt+=temp;
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n;
        while(low<high){
            int mid = low + (high-low)/2;
            int   smMidEle = count(mid,m,n);
            if(smMidEle<k) low  = mid+1;
            else high =mid;
        }
        return low;
    }
};