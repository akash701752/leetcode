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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q ;
        //ans.push_back(root->val);
        q.push(root);
        while(q.size()>0)
        {
            TreeNode *temp = q.front() ;
            //q.pop();
            //queue<TreeNode*> q1(q) ;
            //q1 = q ;
            int mx = temp->val ;
            int size = q.size() ;
            for(int i=0;i<size;i++){
                TreeNode *temp = q.front() ;
                mx = max(mx,q.front()->val) ;
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left) ;
                }
                if(temp->right!=NULL){
                    q.push(temp->right) ;
                }
            }
            ans.push_back(mx) ;
        }
        return ans ;
    }
};
