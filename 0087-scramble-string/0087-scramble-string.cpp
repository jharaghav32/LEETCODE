class Solution {
public:
    unordered_map<string,bool> mp;
    bool solve(string s1,string s2){
        string s = s1+" "+s2;
        if(s1 == s2)
            return true;
        if(s1.length()<=1 || s2.length()<=1)
            return false;
        if(mp.find(s)!= mp.end()) return mp[s];
        bool flag = false;
        int n = s1.length();
        for(int i=1;i<n;i++){
            bool cond1=solve(s1.substr(0,i),s2.substr(n-i)) && solve(s1.substr(i),s2.substr(0,n-i));
            bool cond2=solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i),s2.substr(i));
            if(cond1 || cond2){
                flag=true;
                break;
            }
          
        }
         return mp[s]=flag;
    }
   
    
    bool isScramble(string s1, string s2) {
        if(s1.empty()&& s2.empty())
            return true;
        return solve(s1,s2);
    }
};