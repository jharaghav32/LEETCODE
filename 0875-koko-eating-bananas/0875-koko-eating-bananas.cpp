class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
     sort(piles.begin(),piles.end());
        int low = 1;
        int high=piles[n-1];
        
        while(low<high){
            int mid = (low+high)/2;
            int hrs = 0;
            for (int p : piles)
                hrs += (p + mid - 1) / mid;
            if(hrs>h)
                low=mid+1;
                else
                high=mid;
            
        }
        return low;
    }
};