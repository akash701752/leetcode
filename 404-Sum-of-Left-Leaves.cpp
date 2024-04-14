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
/*
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0 ;
        if(root==NULL || (root->left==NULL &&root->right==NULL)){
            return ans ;
        }
        queue<TreeNode*> q ;
        q.push(root) ;
        bool flag = true ;
        while(q.size()>0)
        {
            int n = q.size() ;
            // flag = true ;
            
            for(int i=0;i<n;i++) 
            {
                TreeNode* curr = q.front() ;
                if(i==0 && flag==true &&(curr->left==NULL && curr->right==NULL)){
                    ans += curr->val ;
                }
                q.pop() ;
                if(curr->left==NULL && curr->right!=NULL){
                    flag = false ;
                }
                if(curr->left){
                    flag = true ;
                    q.push(curr->left) ;
                }
                if(curr->right){
                    q.push(curr->right) ;
                }
            }

        }
        return ans ;
    }
};
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        stack<TreeNode*>s;
        int sum = 0;
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root = root->left;
                if(root && !root->left && !root->right) sum += root->val;
            }
            root = s.top()->right;
            s.pop();
        }
        return sum;
    }
};
