class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int,int>ump;
        for(int i=0;i<jewels.size();i++){
            ump[jewels[i]]++;
        }
        int ans=0;
        for(int i=0;i<stones.size();i++){
            if(ump.find(stones[i])!=ump.end())
                ans++;
        }
        return ans;
    }
};