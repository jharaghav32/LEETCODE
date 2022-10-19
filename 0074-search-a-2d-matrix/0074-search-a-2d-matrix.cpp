class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // We start from top right element and check if it is eual to target than rteturn true
        // if it is greater than target  then we have to find less one so we move to prev column as element in next row is obiviously greater so no need to go to next to row we only have to search in column if it exist return true and when our iterator cross limit it means the element is not found return false;
        int i=0;
        int j = n-1;
        while(j>=0 && i<m){
            if(matrix[i][j]==target)return true;
            else if(matrix[i][j]>target)j--;
            else i++;
        }
        return false;
    }
};