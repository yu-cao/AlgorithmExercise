class Solution {
public:
	int search(vector<int> &nums, int target)
	{
		if (nums.size() == 0) return -1;
		int begin = 0;
		int tail = nums.size() - 1;
		int change = -1;
		for (;;)//先二分法找到突变点
		{
			int mid = (tail + begin) / 2;
			if (nums[mid] < nums[tail])//突变点在左侧，右侧都是升序的
				tail = mid;
			else if (nums[mid] > nums[tail])//突变点在右侧
				begin = mid + 1;
			if (begin == tail)
			{
				change = begin;
				break;
			}
		}
		if (target <= nums[nums.size() - 1])
			return halffind(nums, change, nums.size() - 1, target);
		else return halffind(nums, 0, change - 1, target);
	}

    //普通的二分搜索法
	int halffind(vector<int> &vec, int begin, int tail, int target)
	{
        int mid = (tail - begin) / 2 + begin;
        if(vec[mid] == target) return mid;
		if (begin >= tail)
			return -1;
        else if (vec[mid] < target)
            return halffind(vec, mid + 1, tail, target);
        else if (vec[mid] > target)
            return halffind(vec, begin, mid - 1, target);
        return -1;
	}
};