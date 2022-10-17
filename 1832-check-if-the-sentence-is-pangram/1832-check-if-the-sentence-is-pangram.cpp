class Solution {
public:
    bool checkIfPangram(string sentence) {
       unordered_map<int,int>ump;
        for(int i=0;i<sentence.size();i++){
            ump[sentence[i]]++;
        }
        for(int i=0;i<26;i++){
            char c = 'a'+i;
            if(ump.find(c)==ump.end())return false;
        }
        return true;
        
    }
};