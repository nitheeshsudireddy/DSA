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
    int ans = 0;
    int sumEvenGrandparent(TreeNode* root) {
        if(root->left) find(root->left,root,NULL);
        if(root->right) find(root->right,root,NULL);
        return ans;
    }
    void find(TreeNode* root, TreeNode* parent, TreeNode* grandParent){
        if(root == NULL) return ;

        if(grandParent && grandParent->val % 2 == 0){
            ans += root->val;
        }

        find(root->left, root,parent);
        find(root->right,root,parent); 
        
    }
};
