class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        long long n = spells.size();
        long long m = potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int l=0;
            int h = m-1;
            while(l<=h){
                int mid = (l+h)/2;
                long long val = (long long)spells[i]*(long long)potions[mid];
                if(val>=success){
                    h = mid-1;
                }
                else{
                    l=mid+1;
                }
                
            }
            
          spells[i]=m-l;
        }
        return spells;
    }
};