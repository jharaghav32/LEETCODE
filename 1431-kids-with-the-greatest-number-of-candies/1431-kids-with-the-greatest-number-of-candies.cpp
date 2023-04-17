class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int maxi=candies[0];
        for(int i=1;i<candies.size();i++){
            maxi=max(maxi,candies[i]);
        }
        vector<bool>ans;
        for(int i=0;i<candies.size();i++){
            int curr = candies[i]+extra;
            if(curr>=maxi){
               ans.push_back(true); 
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};