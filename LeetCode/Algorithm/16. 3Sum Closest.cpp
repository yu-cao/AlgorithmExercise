class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int64_t closest = INTMAX_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int temp = nums[i] + nums[l] + nums[r] - target;
                if (abs(temp) < abs(closest))
                    closest = temp;
                if (temp < 0)
                    l++;
                else if (temp > 0)
                    r--;
                else if (temp == 0)
                    return target;
            }
        }
        return closest + target;
    }
};