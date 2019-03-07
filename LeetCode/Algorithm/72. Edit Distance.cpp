class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		//二维dp数组表示word1的字母数与word2的字母数
		//这里先设定两种特殊情况，word1为空串或word2为空串(这两种只有一个选择途径，不断insert/remove)
		for (int i = 1; i <= m; i++)
			dp[i][0] = i;

		for (int j = 1; j <= n; j++)
			dp[0][j] = j;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (word1[i - 1] == word2[j - 1])//如果word2当前位置的值与word1此位置恰好相同相同，就不用变（增删改）
					dp[i][j] = dp[i - 1][j - 1];
				else//如果不相同，就需要考察dp[i-1][j-1](改一个), dp[i][j-1](删一个), dp[i-1][j](加一个)三者的min + 1
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;//状态转移方程
			}
		}
		return dp[m][n];
	}
};