/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL||root == p||root == q) return root;
        TreeNode* Left = lowestCommonAncestor(root->left,p,q);
        TreeNode* Right = lowestCommonAncestor(root->right,p,q);
        
       if (Left && Right) return root;//要找的节点正好分散在左右子树中
       return Left ? Left : Right;//只找到了一个节点，把这个信息向上返回
    }
};