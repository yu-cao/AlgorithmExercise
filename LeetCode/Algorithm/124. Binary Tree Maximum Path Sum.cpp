//方法总结：深度优先，类似于最大子序列的滑动窗口策略
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define MAX(a,b) ((a)>(b)?(a):(b))
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max = -200000;
        maxOfTheChild(root, max);
        return max;
    }
    
    int maxOfTheChild(TreeNode* root, int& max)
    {
        if(root != nullptr)
        {
            int l = maxOfTheChild(root->left, max);
            int r = maxOfTheChild(root->right, max);

            if(l < 0) l = 0;
            if(r < 0) r = 0;

            if(l + r + root->val > max) max = l + r + root->val;

            //return root->val + l + r;//注意是path，不等效于这颗二叉树的连通最大
            return root->val + MAX(l, r);
        }
        return 0;
    }
};