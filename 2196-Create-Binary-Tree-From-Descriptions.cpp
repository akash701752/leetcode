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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp; // {value of node, address of the node}
        unordered_set<int> childSet; // contains all the child nodes

        // {parent, child, isLeft}
        for(auto it: descriptions) // Iterate through the given 'descriptions' array
        {
            int parent = it[0]; 
            int child = it[1];
            int isLeft = it[2];

            if(mpp.find(parent) == mpp.end())
                mpp[parent] = new TreeNode(parent);
            
            // Same for the 'child' node
            if(mpp.find(child) == mpp.end())
                mpp[child] = new TreeNode(child);
            
            if(isLeft)
                mpp[parent] -> left = mpp[child]; // Assign the 'parent' left to the 'child'
            else
                mpp[parent] -> right = mpp[child]; // Assign the 'parent' right to the 'child'

            childSet.insert(child); // Put the 'child' node in the set
        }

        for(auto it: descriptions)
        {
            int parent = it[0];
            
            if(!childSet.count(parent))
                return mpp[parent];
        }

        return NULL;
    }
};
