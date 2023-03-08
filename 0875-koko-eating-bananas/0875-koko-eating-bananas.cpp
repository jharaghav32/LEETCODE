class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
   
        int low = 1;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            high=max(high,piles[i]);
        }
        
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