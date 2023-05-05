class Solution {
public:
    bool isVowel(char c){
         if(c=='a' || c=='e' ||  c=='i' || c=='o' || c=='u'){
                return true;
            }
        return false;
    }
    int maxVowels(string s, int k) {
        int cnt=0;
        int ans=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                cnt++;
            }
        }
        ans=max(ans,cnt);
        int i=0;
        int j=k;
        while(j<s.size()){
            if(isVowel(s[i])){
                cnt--; 
            }
            if(isVowel(s[j])){
                cnt++;
            }
            i++;
            j++;
            ans = max(ans,cnt);
        }
        return ans;
    }
};