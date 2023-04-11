class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        string ans ="";
        for(int i=0;i<n;i++){
            if(s[i]=='*')
            {
                if(ans.empty()==false){
                    ans.pop_back();
                }
            }
            else
                ans += s[i];
    }
        return ans;
    }
};