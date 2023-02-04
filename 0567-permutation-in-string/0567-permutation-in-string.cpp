class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>ump1;
        bool np=true;
        for(int i=0;i<s1.size();i++){
            ump1[s1[i]]++;
        }
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2)return false;
        for(int i=0;i<=n2-n1;i++){
            int j = n1+i-1;
        unordered_map<char,int>ump2;
            np=true;
            for(int k=i;k<=j;k++){
                ump2[s2[k]]++;
            }
            for(auto it : ump1){
                if(it.second==ump2[it.first])continue;
                else {
                    np=false;
                    break;
                }
            }
            if(np)return true;
        }
        if(np)return true;
        else return false;
    }
};