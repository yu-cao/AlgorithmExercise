//回溯法，先排好序使得回溯法可以正常运行，然后自己定义一个函数进行回溯（DFS策略）
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		vector<int> combination;
		combinationSum(candidates, target, res, combination, 0);
		return res;
	}

	void combinationSum(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &combination, int begin)
	{
		if (!target)
		{
			res.push_back(combination);//找到一组解
			return;
		}
		for (int i = begin; i != candidates.size() && candidates[i] <= target; ++i)
		{
			combination.push_back(candidates[i]);
			combinationSum(candidates, target - candidates[i], res, combination, i);//不断用vector中的sum和target之间进行比较
			combination.pop_back();//如果不行就回溯出来
		}
	}
};