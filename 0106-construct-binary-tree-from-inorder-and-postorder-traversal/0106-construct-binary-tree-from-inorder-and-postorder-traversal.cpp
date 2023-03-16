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
    TreeNode* construct(vector<int>&inorder,vector<int>&postorder,int instart,int inend,int postart,int poend,unordered_map<int,int>&mp){
        if(postart>poend || instart>inend)return NULL;
        TreeNode* newnode = new TreeNode(postorder[poend]);
        int pos = mp[postorder[poend]];
        int numsleft = pos-instart;
        newnode->left = construct(inorder,postorder,instart,pos-1,postart,postart+numsleft-1,mp);
        newnode->right = construct(inorder,postorder,pos+1,inend,postart+numsleft,poend-1,mp);
        return newnode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = construct(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mp);
        return root;
    }
};