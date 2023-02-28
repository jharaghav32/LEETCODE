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
    unordered_map<string,int>ump;
    vector<TreeNode*>ans;
    string serial(TreeNode* root){
        if(root==NULL)return "";
        string str = "("+serial(root->left)+to_string(root->val)+serial(root->right)+")";
        if(ump[str]==1)ans.push_back(root);
        ump[str]++;
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serial(root);
        return ans;
    }
};