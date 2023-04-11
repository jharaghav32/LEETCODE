class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int j=0;
       for(int i=0;i<n;i++){
           if(s[i]=='*')
           {
               j--;
           }
           else{
               s[j]=s[i];
               j++;
           }
       }
        return s.substr(0,j);
    }
};