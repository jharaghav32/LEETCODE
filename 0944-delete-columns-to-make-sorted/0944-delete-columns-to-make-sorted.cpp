class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r = strs.size();
        int c = strs[0].size();
        int ans =0;
        for(int i=0;i<c;i++){
            for(int j=0;j<r-1;j++){
                if(strs[j+1][i]-strs[j][i]<0){
                    ans+=1;
                    break;
                }
            }
        }
        return ans;
    }
};