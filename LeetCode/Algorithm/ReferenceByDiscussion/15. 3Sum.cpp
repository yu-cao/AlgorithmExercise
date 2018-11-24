class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        //i is the leftist (the main to hold)
        //l is the left of the rest, r is the right of the rest
        for (auto i = 0; i < nums.size(); i++)
        {
            if ((i > 0) && (nums[i] == nums[i - 1]))
                continue;

            int l = i + 1;
            int r = nums.size() - 1;//Not to be auto, otherwise in line 35, r will be the large number cause error
            while (l < r)
            {
                int s = nums[i] + nums[l] + nums[r];

                //Adjust the result compare to the zero
                if (s > 0)
                    r--;
                else if (s < 0)
                    l++;
                else
                {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});

                    //Case of [-4,2,2,2,2,3], otherwise will cause repeat
                    while (nums[l] == nums[l + 1])
                        l++;
                    while (nums[r] == nums[r - 1])
                        r--;

                    //Not directly break; for the case of [-4,-1,0,0,1]
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
