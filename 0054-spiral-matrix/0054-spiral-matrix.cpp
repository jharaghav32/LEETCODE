class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // we have to mark the top,left ,up,down index and 
        // also mark the direction pointer such as lefttoright,righttolefft,toptodown,downtotop
        int m =matrix.size();
        int n =matrix[0].size();
        int top=0;
        int down =m-1;
        int left=0;
        int rt=n-1;
        bool ltr,ttd,rtl;
        vector<int> ans;
        ltr=true;
        ttd=false;
        rtl=false;
        while(top<=down && left<=rt){
            if(ltr){
                for(int i=left;i<=rt;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
                ttd=true;
                ltr=false;
            }
            else if(ttd){
                for(int i=top;i<=down;i++){
                    ans.push_back(matrix[i][rt]);
                }
                rt--;
                ttd=false;
                rtl=true;
                
            }
            else if(rtl){
                for(int i=rt;i>=left;i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
                rtl=false;
            }
            else{
                for(int i=down;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                ltr=true;
            }
        }
        return ans;
    }
};