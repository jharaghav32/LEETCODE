/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum =0;
    void CalcNumber(TreeNode* root,int Num){
        if(!root->left && !root->right){
            sum+=Num;
            return ;
        }
        if(root->left)CalcNumber(root->left,Num*10+root->left->val);
        if(root->right)CalcNumber(root->right,Num*10+root->right->val);
    }
    int sumNumbers(TreeNode* root) {
        CalcNumber(root,root->val);
        return sum;
    }
};