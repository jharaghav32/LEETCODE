class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum += mat[i][i];
        }
        for(int i=0;i<n;i++){
            int  k = n-1-i;
            sum += mat[i][k];
        }
        if(n%2!=0){
            int cmn = n/2;
            sum = sum - mat[cmn][cmn];
        }
        return sum;
    }
};