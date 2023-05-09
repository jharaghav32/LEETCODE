class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>mat(n,vector<int>(n));
        int tp=0;
        int dwn=n-1;
        int left=0;
        int right=n-1;
        int ele = 1;
        while(tp<=dwn && left<=right){
            for(int i=left;i<=right;i++){
                mat[tp][i]=ele;
                ele++;
            }
            tp++;
            for(int i=tp;i<=dwn;i++){
                mat[i][right]=ele;
                ele++;
                
            }
            right--;
            for(int i=right;i>=left;i--){
                mat[dwn][i]=ele;
                ele++;
                 
            }
            dwn--;
            for(int i=dwn;i>=tp;i--){
                mat[i][left]=ele;
                ele++;
               
            }
            left++;
        }
        return mat;
    }
};