class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n  = arr.size();
        int low=0;
        int hi=n-1;
        while(low<=hi){
            int mid = (low+hi)/2;
            if(arr[mid]-(mid+1)<k)
                low=mid+1;
            else
                hi=mid-1;
        }
        if(hi==-1)return k;
        return arr[hi]+(k-(arr[hi]-(hi+1)));
    }
};