class Solution {
public:
    string convert(string s, int numRows) {
        bool inc=true;
        int elem=0;
        int idx=1;
        map<int,vector<char>>mp;
        while(elem<s.size()){
            mp[idx].push_back(s[elem]);
            if(idx==1 && !inc ){
                inc=true;
            }
            if(idx==numRows && inc && idx!=1){
                inc=false;
            }
            inc==true?idx++:idx--;
            elem++;
        }
        string ans="";
        for(auto it :mp){
            for(auto c : it.second){
                ans+=c;
            }
        }
        return ans;
    }
};