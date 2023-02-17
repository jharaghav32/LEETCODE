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
    vector<int>nodes;
    void traversal(TreeNode* root){
        nodes.push_back(root->val);
        if(root->left)traversal(root->left);
        if(root->right)traversal(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        traversal(root);
        int n = nodes.size();
        int ans =INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=abs(nodes[i]-nodes[j]);
                ans = min(ans,diff);
            }
        }
        return ans;
    }
};