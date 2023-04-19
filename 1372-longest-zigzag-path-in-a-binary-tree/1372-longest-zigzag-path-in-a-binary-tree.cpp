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
    int ans=0;
    void traversal(TreeNode*root,bool left,int step){
        if(root==NULL)return;
         ans = max(ans,step);
        if(left){
            traversal(root->left,false,step+1);
            traversal(root->right,true,1);
        }
        else{
             traversal(root->right,true,step+1);
            traversal(root->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        traversal(root,true,0);
       
        return ans;
    }
};