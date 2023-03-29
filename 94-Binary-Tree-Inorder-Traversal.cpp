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
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans ;
//         if(root==NULL){
//             return ans ;
//         }
//         TreeNode *curr = root;
//         while(curr!=NULL)
//         {
//             if(curr->left==NULL){
//                 ans.push_back(curr->val) ;
//                 curr = curr->right ;
//             }
//             else{
//                 TreeNode *prev = curr->left ;
//                 while(prev->right!=NULL && prev->right!=curr){
//                     prev = prev->right ;
//                 }
//                 if(prev->right==NULL){
//                     prev->right = curr ;
//                     curr = curr->left ;
//                 }
//                 else{
//                     prev->right = NULL ;
//                     ans.push_back(curr->val);
//                     curr = curr->right ;
//                 }
//             }
//         }
//         return ans ;
//     }
// };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ;
        if(root==NULL){
            return ans ;
        }
        TreeNode *curr = root;
        stack<TreeNode*> st ;
        //st.push(root);
        while(true){
            if(curr!=NULL){
                st.push(curr) ;
                curr = curr->left ;
            }
            else{
                if(st.size()==0){
                    break ;
                }
                curr = st.top() ;
                st.pop() ;
                ans.push_back(curr->val) ;
                curr = curr->right ;
            }
        }
        return ans ;
    }
};
