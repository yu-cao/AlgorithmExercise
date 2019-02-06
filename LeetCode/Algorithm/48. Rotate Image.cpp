/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
//Best Solution
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void rotate(vector<vector<int>> &matrix)
	{
		reverse(matrix.begin(), matrix.end());//首先交换第一行与最后一行

		//沿着对角线交换即可完成旋转
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = i + 1; j < matrix.size(); j++)
			{
				swap(matrix[i][j],matrix[j][i]);
			}
		}
	}
};

//同理可得反旋转
/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/