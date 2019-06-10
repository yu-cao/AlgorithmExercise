//找到递推式为f(n) = f(0)f(n-1) + f(1)f(n-2) +...+ f(n-1)f(0)
//编写dp算法
class Solution {
public:
	int numTrees(int n) {
		int dp[n+1];
		memset(dp,0,sizeof(int) * (n+1));
		dp[0] = 1;
		for(int i = 1; i <= n;i++)
			for(int j = 0; j < i;j++)
				dp[i] += dp[j] * dp[i-j-1];
		return dp[n];
	}
};