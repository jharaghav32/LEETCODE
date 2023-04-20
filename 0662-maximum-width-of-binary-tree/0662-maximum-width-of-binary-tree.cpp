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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans =0;
        int first;
        int last;
        while(!q.empty()){
            int mini = q.front().second; // here we store the minimal index of that level that is sure the leftmost element
            int n = q.size();
            for(int i=0;i<n;i++){
                
                unsigned int id = q.front().second-mini;
                TreeNode* element = q.front().first;
                q.pop();
                if(id==0) first = id;
                if(i==n-1) last = id;
                if(element->left)q.push({element->left,2*id+1});
                if(element->right)q.push({element->right,2*id+2});
            }
            ans= max(ans,(last-first+1));
        }
        return ans;
    }
};