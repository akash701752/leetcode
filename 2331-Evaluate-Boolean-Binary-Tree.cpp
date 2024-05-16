bool isLeaf(TreeNode *root){
        if(!(root->left && root->right)) return true;
        return false;
    }
    
    bool dfs(TreeNode *root){
        if(root==nullptr) return false;
        if(isLeaf(root)) return root->val;
        bool b1 = dfs(root->left);
        bool b2 = dfs(root->right);
        if(root->val == 2){
            return b1|b2;
        }
        return b1&b2;
    }
    
    bool evaluateTree(TreeNode* root) {
        if(!root) return false;
        if(root->val==0 || root->val==1) return root->val;
        return dfs(root);
    }
