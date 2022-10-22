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
        // range of elment is [1,high];
        while(low<high){
            int mid = low + (high-low)/2;
            int   smMidEle = count(mid,m,n); // ye calculate krta hai ki kitne element matrix 
            // less than and eqal to mid hai 
            if(smMidEle<k) low  = mid+1;//Agar no of element less than equal to mid is 
            // less than k agar aisa hai to eska matlab hame mid ko badhana padega tabhi jabhi element milenge so we increase our low pointer to mid+1;
            else high =mid;// and agar element k se jayada hogye to mid ko ghantan padega so
            // we move our high pointer to mid  
            //and atlast when low becomes equal to high we get the kth smallest element 
        }
        return low;
    }
};