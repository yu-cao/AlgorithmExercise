//转换到最经典的中序遍历，然后转换到vector即可
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
	vector<int> inorderTraversal(TreeNode* root) {
		inorder(root);
		int temp;
		vector<int> ans;
		while(ss >> temp)
			ans.push_back(temp);
		return ans;
	}

private:
	stringstream ss;
	void inorder(TreeNode* root)
	{
		if(root == nullptr) return;

		inorder(root->left);
		ss << root->val << " ";
		inorder(root->right);
	}
};