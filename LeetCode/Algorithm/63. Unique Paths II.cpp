class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));

        //二维dp
		dp[0][1] = 1;//为了让[1][1]位置为1，不能直接设[1][1] = 1，这样会导致dp之后重新刷新引发[1][1] = 0
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (obstacleGrid[i - 1][j - 1] == 0)
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//状态转移方程
		return dp[m][n];

        //一维dp
		// vector<long> dp(n + 1, 0);
		// dp[1] = 1;
		// for(int i = 0; i < m; i++)
		// 	for(int j = 1; j <= n; j++)
		// 		if(obstacleGrid[i][j-1] == 0)
		// 			dp[j] = dp[j] + dp[j-1];
		// 		else dp[j] = 0;
		// return dp[n];
	}
};