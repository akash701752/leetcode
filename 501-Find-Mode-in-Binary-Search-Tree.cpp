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
    void solve(TreeNode *root, unordered_map<int,int> &mp){
        if(root==NULL){
            return ;
        }
        mp[root->val]++;
        solve(root->left,mp);
        solve(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp ;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        solve(root,mp);
        int mx = 0 , val = root->val ;
        for(auto it:mp){
            //cout<<it.first <<" "<<it.second <<endl;
            if(it.second>mx){
                ans.clear();
                mx = it.second ;            
            }
            if(it.second>=mx){
                ans.push_back(it.first);
            }
        }
        //ans.push_back(val);
        return ans;
    }
};
