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
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode *> q1, q2;
		vector<vector<int>> ans;
		vector<int> temp;
		if(root == NULL) return vector<vector<int>>();
		q1.push(root);
		while(!(q1.empty()&&q2.empty()))
		{
			if(q1.empty())
			{
				while(!q2.empty())
				{
					TreeNode *t = q2.front();
					q2.pop();
					if(t->left != NULL)
						q1.push(t->left);
					if(t->right != NULL)
						q1.push(t->right);
					temp.push_back(t->val);
				}
				ans.push_back(temp);
			}
			else if(q2.empty())
			{
				while(!q1.empty())
				{
					TreeNode *t = q1.front();
					q1.pop();
					if(t->left != NULL)
						q2.push(t->left);
					if(t->right != NULL)
						q2.push(t->right);
					temp.push_back(t->val);
				}
				ans.push_back(temp);
			}
			while(!temp.empty())
				temp.pop_back();
		}
		return ans;
	}
};