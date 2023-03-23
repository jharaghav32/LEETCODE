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
class CBTInserter {
public:
    queue<TreeNode*>q;
    vector<TreeNode*>v;
    int idx;
    CBTInserter(TreeNode* root) {
        idx=0;
        q.push(root);
        while(!q.empty()){
            int n  = q.size();
            for(int i=0;i<n;i++){
            auto node = q.front();
              q.pop();
                v.push_back(node);
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            }
        }
    }
    
    int insert(int val) {
        while(idx<v.size()){
          auto node = v[idx];
            if(node->left && node->right){
                idx++;
            }
            else if(!node->left || !node->right){
                TreeNode* newnode= new TreeNode(val);
                if(!node->left)node->left=newnode;
                else node->right = newnode;
                v.push_back(newnode);
                return node->val;
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return v[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */