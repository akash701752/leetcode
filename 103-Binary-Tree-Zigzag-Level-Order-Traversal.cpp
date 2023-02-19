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
    void bfs(TreeNode* root,vector<vector<int>> &res)
    {
        if(root==NULL){
            return ;
        }
        queue<TreeNode*> q ;
        q.push(root) ;
        int level = 0;
        while(q.size()>0)
        {
            int size = q.size() ;
            vector<int> v;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front() ;
                q.pop() ;
                cout<<temp->val <<" ";
                if(temp->left){
                    q.push(temp->left) ;
                }
                if(temp->right){
                    q.push(temp->right) ;
                }
                if(level%2!=0){
                    v.insert(v.begin()+0,temp->val) ;
                }
                else{
                    v.push_back(temp->val) ;
                }
            }
            level++ ;
            res.push_back(v) ;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res ;
        bfs(root,res) ;
        return res ;
    }
};
