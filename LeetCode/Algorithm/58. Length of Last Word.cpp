#include <iostream>
using namespace std;

class Solution
{
  public:
	int lengthOfLastWord(string s)
	{
		int count = 0;
		int i = s.length() - 1;
		for (; i >= 0; i--)
		{
			if (s[i] == ' ')
				continue;
			else
				break;
		}
		for (; i >= 0; i--)
		{
			if (s[i] == ' ')
				return count;
			count++;
		}
		return count;
	}
};

//string s = "a ";//conner case