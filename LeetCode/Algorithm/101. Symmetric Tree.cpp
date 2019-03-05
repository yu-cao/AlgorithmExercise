/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//队列（一般在BFS中常常使用）
class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		TreeNode *left, *right;
		if (!root)
			return true;

		queue<TreeNode*> q1, q2;
		q1.push(root->left);
		q2.push(root->right);
		while (!q1.empty() && !q2.empty()){
			left = q1.front();
			q1.pop();
			right = q2.front();
			q2.pop();
			if (left == NULL && right == NULL)
				continue;
			if (left == NULL || right == NULL)
				return false;
			if (left->val != right->val)
				return false;
			q1.push(left->left);
			q1.push(left->right);
			q2.push(right->right);
			q2.push(right->left);
		}
		return true;
	}
};