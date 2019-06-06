//思路：转化为指针操作
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int *buffer1 = new int[preorder.size()+1];//多开一个，防止下面构建时right出错
		if (!preorder.empty())
			memcpy(buffer1, &preorder[0], preorder.size()*sizeof(int));

		int *buffer2 = new int[inorder.size()+1];
		if (!inorder.empty())
			memcpy(buffer2, &inorder[0], inorder.size()*sizeof(int));

		return build(buffer1,buffer2,preorder.size(),inorder.size());
	}

private:
	TreeNode* build(int* preorder, int* inorder, int size_pre, int size_in)
	{
		if(size_pre == 0 || size_in == 0) return nullptr;

		TreeNode *root = new TreeNode(0);
		root->val= preorder[0];

		int i;
		for(i = 0;i<size_in;i++)
			if(inorder[i] == preorder[0]) break;

		root->left = build(&preorder[1],inorder,i,i);
		root->right = build(&preorder[i+1],&inorder[i+1],size_pre-i-1,size_in-i-1);

		return root;
	}
};
