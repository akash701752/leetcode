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
    int countPairs(TreeNode* root, int distance) {
        auto ans = 0;

        function<deque<int> * (TreeNode *&)> dfs = [&](auto &node) -> deque<int> * {
            if (!node){
                return nullptr;
            }

            if (node->left == nullptr && node->right == nullptr) {
                auto res = new deque<int>(distance,0);
                (*res)[0] = 1;
                return res;
            }

            auto left = dfs(node->left);
            if( left != nullptr ) {
                left->emplace_front(0);
                left->pop_back();
            }
            auto right = dfs(node->right);
            if( right != nullptr) {
                right->emplace_front(0);
                right->pop_back();
            }

            if (left && right){
                for(auto i = 1; i<(*left).size();i++) {
                    ans +=  (*left)[i] * accumulate((*right).begin()+1, (*right).end() - i + 1,0);
                    (*left)[i] += (*right)[i];
                }
                return left;
            }else if(left)
                return left;
            return right;
        };
        dfs(root);
        return ans;
    }
};
