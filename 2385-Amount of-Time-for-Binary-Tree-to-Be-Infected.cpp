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
    map<int,int> mp;  // <node,distance from start>
    int ans;
    int amountOfTime(TreeNode* root, int start) {
        ans=0;
        TreeNode* head=root;
        
        go(root,-1,start);  // first time visit to mark start & its children
        go(head,-1,start); // second visit to propagate the values
        
        for(auto &x:mp) {
            ans=max(ans,x.second);
        }
        return ans;
             
    }
    int go(TreeNode* node,int val,int start)
    {
        if(node==NULL) return -1;
        
        int goVal=-1;  // to be sent to children
        int currVal=node->val;
        
        if(mp.find(currVal)!=mp.end()) {
            goVal=mp[currVal]+1;  
        } 
        else if(currVal==start){ 
            mp[currVal]=0; goVal=1; 
        } 
        else if(val!=-1){
            mp[currVal]=val; goVal=val+1;
        }    
        int left=go(node->left,goVal,start);
        int right=go(node->right,goVal,start);
        
        
        if(currVal==start){
            return 1;      
        }
        if(left!=-1){ 
            mp[currVal]=left; 
            return left+1;
        }  
        
        if(right!=-1) { 
            mp[currVal]=right; 
            return right+1;
        } 
        
        return -1;    
    }
};
