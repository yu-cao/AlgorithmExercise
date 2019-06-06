//这道题题面描述不清晰，意义不是很大，面试时需要多沟通确认题意
//暂时理解按照下面代码吧
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
	void flatten(TreeNode *root) {
		TreeNode *now = root;
		while (now)
		{
            if(now->left)
            {
                TreeNode *pre = now->left;
                while (pre->right != nullptr)
                    pre = pre->right;//root左节点的最右节点
                pre->right = now->right;
                now->right = now->left;
                now->left = nullptr;
            }
			now = now->right;
		}
	}
};