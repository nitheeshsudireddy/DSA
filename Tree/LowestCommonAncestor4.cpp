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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(root == NULL) return NULL;
        for(int i=0;i<nodes.size();i++){
            if(root->val == nodes[i]->val){
                return root;
            }
        } 
        TreeNode* left = lowestCommonAncestor(root->left, nodes);
        TreeNode* right = lowestCommonAncestor(root->right,nodes);
        if(left != NULL && right != NULL) return root;
        if(left == NULL) return right;
        else return left;
    }

};
