class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>mp;
        int pss=0;
        for(int i=0;i<trips.size();i++){
            mp[trips[i][1]]+= trips[i][0];
            mp[trips[i][2]]-= trips[i][0];
        }
        for(auto it : mp){
            pss+=it.second;
            if(pss>capacity)return false;
        }
        return true;
    }
};