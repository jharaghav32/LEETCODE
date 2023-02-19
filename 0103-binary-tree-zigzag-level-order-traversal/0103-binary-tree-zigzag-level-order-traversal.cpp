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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
                vector<vector<int>> ans;

        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        int l = 1;
        while(!q.empty()){
            vector<int>level;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* element = q.front();
                q.pop();
                if(element!=NULL){
                level.push_back(element->val);
                if(element->left)q.push(element->left);
                if(element->right)q.push(element->right);
                }
            }
            if(l%2==0){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            l++;
        }
        return ans;
    }
};