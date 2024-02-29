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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q ;
        q.push(root) ;
        bool ans = true ;
        int level = 0 ;
        while(q.size()>0)
        {
            int n = q.size() ;
            TreeNode* node = q.front() ;
            //q.pop() ;
            int prev = node->val ;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            q.pop();
            if(level%2==0 && prev%2==0){
                ans = false;
                break;
            }
            if(level%2==1 && prev%2==1){
                ans = false;
                break;
            }
            for(int i=1;i<n;i++){
                TreeNode* node = q.front() ;
                if(level%2==0){
                    if(prev%2==0 || node->val %2== 0 || prev >= node->val){
                        ans = false ;
                        break;
                    }
                    else{
                        prev = node->val;
                    }
                }
                else{
                    if(prev%2==1 || node->val%2==1 || prev <= node->val){
                        ans = false ;
                        break;
                    }
                    else{
                        prev = node->val;
                    }
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                q.pop();
            }
            if(ans==false){
                break;
            }
            level++;
        }
        return ans;
    }
};
