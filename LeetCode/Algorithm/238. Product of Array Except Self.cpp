class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> a, b,ans;
        int tmp = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            tmp *= nums[i];
            a.push_back(tmp);
        }
        tmp = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            tmp *= nums[i];
            b.push_back(tmp);
        }

        ans.push_back(b[nums.size() - 2]);//Fist one
        for (int i = 1; i < nums.size() - 1; i++)
            ans.push_back(a[i - 1] * b[nums.size() - i - 2]);
        ans.push_back(a[nums.size() - 2]);//Final one
        return ans;
    }
};