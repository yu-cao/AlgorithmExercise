class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        for (auto tmp = nums.begin(); tmp != nums.end();)
        {
            if (*tmp == val)
            {
                auto tmp1 = tmp;
                tmp--;
                nums.erase(tmp1);
                tmp++;
            }
            else 
                tmp++;
        }
        return nums.size();
    }
};