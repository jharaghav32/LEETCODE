class Solution {
public:
    unordered_map<string,bool> mp;
    bool solve(string s1,string s2){
        string s = s1+" "+s2;
        if(s1 == s2)
            return mp[s]= true;
        if(s1.length()<=1 || s2.length()<=1)
            return mp[s]= false;
        if(mp.find(s)!= mp.end()) return mp[s];
        // checking if frequency of both string is not same then it is not pssble to 
        // make  a scrambled string and avoid necessary calls of recursion by checking frequency
        vector<int>frq1(26,0);
                vector<int>frq2(26,0);
        for(int i=0;i<s1.size();i++){
            frq1[s1[i]-'a']++;
            frq2[s2[i]-'a']++;
        }
        if(frq1!=frq2)return mp[s]=false;

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
    // time complexity is same as mcm --->O(N3)
};