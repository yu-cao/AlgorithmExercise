#include<iostream>
using namespace std;

class Solution
{
  public:
	int climbStairs(int n)
	{
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		long long n_minus_1 = 2;
		long long n_minus_2 = 1;
		long long store = 0;
		for (int i = 3; i <= n; i++)
		{
			store = n_minus_1 + n_minus_2;

			n_minus_2 = n_minus_1;
			n_minus_1 = store;
		}
		return store;
	}
};