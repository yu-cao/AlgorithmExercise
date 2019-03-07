class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;
		int maxL = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (!stk.empty() && s[i] == ')' && s[stk.top()] == '(')
			{
				stk.pop();
				if (stk.empty())
					maxL = max(maxL, i + 1);
				else
					maxL = max(maxL, i - stk.top());//这是最为重要的一步，直接使用相对位置进行计算距离
			}
			else
				stk.push(i);
		}
		return maxL;
	}
};