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
	int maxLevelSum(TreeNode* root) {
		if(not root) return 0;
		int ans=0;
		int MAX=INT_MIN;
		queue<TreeNode*> q;
		q.push(root);
		int step=1;
		while(!q.empty()){
			int len=q.size();
			int res=0;
			while(len>0){
				len--;
				TreeNode* cur=q.front();
				q.pop();
				res+=cur->val;
				if(cur->left){
					q.push(cur->left);
				}
				if(cur->right){
					q.push(cur->right);
				}
			}
			if(res>MAX){
				ans=step;
				MAX=res;
			}
			step++;
		}
		return ans;
	}
};
