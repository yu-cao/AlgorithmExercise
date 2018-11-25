class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (unsigned int i = 0; i != nums.size(); i++)
        {
            if ((i > 0) && (nums[i] == nums[i - 1]))
                continue;
            for (unsigned int j = i + 1; j < nums.size(); j++)
            {
                if ((j > (i + 1)) && (nums[j] == nums[j - 1]))
                    continue;

                int l = j + 1;
                int r = nums.size() - 1;

                while (l < r)
                {
                    int s = nums[i] + nums[j] + nums[l] + nums[r];

                    if (s < target)
                        l++;
                    else if (s > target)
                        r--;
                    else if (s == target)
                    {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});

                        while (nums[l] == nums[l + 1])
                            l++;
                        while (nums[r] == nums[r - 1])
                            r--;

                        l++;
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
