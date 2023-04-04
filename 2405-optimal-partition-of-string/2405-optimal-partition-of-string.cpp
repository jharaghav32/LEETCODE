class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>ump;
        int n = s.size();
        int ans =1;
        for(int i=0;i<n;i++){
            if(ump[s[i]])
            {
                ans++;
                ump.clear();
            }
            ump[s[i]]++;
        }
        return ans;
    }
};