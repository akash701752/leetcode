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
    map<int, int> mp, path;
    map<int, priority_queue<int>> level;
    void f(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while (!q.empty()) {
            int s = q.size();
            lvl++;
            while (s--) {
                auto it = q.front();
                q.pop();
                level[lvl].push(mp[it->val]);
                if (it->right)
                    q.push(it->right);
                if (it->left)
                    q.push(it->left);
            }
        }
    }
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int left = 0, right = 0;
        if (root->left)
            left = dfs(root->left);
        if (root->right)
            right = dfs(root->right);

        return mp[root->val] = 1 + max(left, right);
    }
    void dfs2(TreeNode* root) {
        if (!root)
            return;
        path[root->val]++;
        if (root->left && root->right) {
            if (mp[root->left->val] > mp[root->right->val]) {
                dfs2(root->left);
            } else
                dfs2(root->right);
        } else if (!root->right) {
            dfs2(root->left);
        } else if (!root->left) {
            dfs2(root->right);
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root);
        dfs2(root);
        // for (auto it : mp) {
        //     cout << it.first << " " << it.second << endl;
        // }
        vector<int> ans;
        int h = mp[root->val];
        f(root);
        for (auto it : queries) {
            int nh = h;
            if (path.find(it) != path.end()) {
                // the node removed is from the path of the max height
                int lvl = h-mp[it]+1;//find the level from top
                if(level[lvl].size() <= 1){
                    ans.push_back(h-mp[it]-1);//if not other node on same level
                }
                else{
                    int t = level[lvl].top();
                    level[lvl].pop();
                    ans.push_back(lvl+level[lvl].top()-2);
                    //the new height using the second max. height
                    level[lvl].push(t);
                }
            } else {
                ans.push_back(nh - 1);
            }
        }
        return ans;
    }
};
