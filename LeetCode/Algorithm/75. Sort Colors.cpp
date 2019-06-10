//简单的桶排序
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int red = 0, white = 0, blue = 0;
		for (auto e : nums)
		{
			switch(e)
			{
				case 0:
					red++;
					break;
				case 1:
					white++;
					break;
				case 2:
					blue++;
					break;
			}
		}
		int i = 0;
		for(; i< red;i++)
			nums[i] = 0;
		for(; i < red + white; i++)
			nums[i] = 1;
		for(; i < red+white+blue;i++)
			nums[i] = 2;
	}
};