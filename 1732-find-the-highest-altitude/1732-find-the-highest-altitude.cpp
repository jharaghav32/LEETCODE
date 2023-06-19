class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int start=0;
        for(int i=0;i<gain.size();i++){
            start += gain[i];
            maxi=max(maxi,start);
        }
        return maxi;
    }
};