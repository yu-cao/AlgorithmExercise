//典型的DP问题
//转移方程：S[i][j] = min(S[i - 1][j], S[i][j - 1]) + grid[i][j]
class Solution {
public:
	int minPathSum(vector<vector<int>> &grid)
	{
		//m行 x n列矩阵，初始值都是[0][0]处的值
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> sum(m, vector<int>(n, grid[0][0]));

		//把两条边计算出min（只有一条路）
		for (int i = 1; i < m; i++)
			sum[i][0] = sum[i - 1][0] + grid[i][0];
		for (int j = 1; j < n; j++)
			sum[0][j] = sum[0][j - 1] + grid[0][j];

		//DP策略
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				sum[i][j]  = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
		return sum[m - 1][n - 1];
	}
};