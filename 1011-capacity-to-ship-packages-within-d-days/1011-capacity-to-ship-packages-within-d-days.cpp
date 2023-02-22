class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int hi=0;
        int lo=INT_MIN;
        for(auto w : weights){
            hi+=w;
            lo = max(lo,w);
        }
    
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cur = 0, need = 1;
            for (int w : weights) {
                if (cur + w > mid) {
                    cur = 0;
                    need++;
                }
                cur += w;
            }
            if (need <= days) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }   
    
};