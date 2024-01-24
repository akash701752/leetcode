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
    void explore( TreeNode *root,int &ans,vector<int> &freq,int &total )
    {
        if(!root)
            return ;
        freq[ root->val ]++;
        total++;
        explore(root->left,ans,freq,total);
        explore(root->right,ans,freq,total);
        
        if( !root->left && !root->right )
        {
            int odd=0;
            for(int i=0;i<10;i++)
                odd+= freq[i]%2;
            if(!total%2)
                ans++;
            else if( odd<=1 )
                ans++;
        }
        
        freq[ root->val ]--;
        total--;
    }
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        int ans=0, total=0;
        vector<int> freq(10,0);
        explore(root,ans,freq,total);
        return ans;
    }
};
