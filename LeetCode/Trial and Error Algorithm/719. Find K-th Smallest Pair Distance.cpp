class Solution{
public:
    int smallestDistancePair(vector<int> &nums, int k){
        sort(nums.begin(), nums.end());
        int d = *--nums.end() - *nums.begin();
        int l = 0, r = d;
        
        for (int count = 0; l < r; count = 0)
        {
            int m = (l + r) / 2;
            for (int i = 0, j = 0; i < nums.size(); i++)
            {
                while (j < nums.size() && nums[j] <= nums[i] + m)
                    j++;
                count += j - i - 1;
            }
            
            if (count < k)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};