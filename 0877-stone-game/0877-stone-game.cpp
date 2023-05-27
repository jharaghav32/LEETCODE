class Solution {
public:
    int dp[501][501];
    int findStone(vector<int>&piles,int s,int e){
        
        if(s>e)return  0;
        if(dp[s][e]!=-1)return dp[s][e];
        
        return dp[s][e]=max(piles[s]-findStone(piles,s+1,e),piles[e]-findStone(piles,s,e-1));
        // if(move){
        //     int start = piles[s]+findStone(piles,s+1,e,false);
        //     int end = piles[e]+findStone(piles,s,e-1,false);
        //     return dp[s][e]=max(start,end);
        // }
        // else{
        //     int start = findStone(piles,s+1,e,true)-piles[s];
        //     int end = findStone(piles,s,e-1,true)-piles[e];
        //     return dp[s][e]=min(start,end);
        // }
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
       if(findStone(piles,0,piles.size()-1)>0)return true;
        return false;
    }
};