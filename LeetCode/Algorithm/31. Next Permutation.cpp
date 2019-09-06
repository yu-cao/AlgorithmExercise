class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        //找到最大的紧挨着颠倒的k
        for(k = n - 2; k >= 0; k--)
        {
            if(nums[k] < nums[k+1])
                break;
        }
        if(k < 0)//已经是最大的数据了
            reverse(nums.begin(), nums.end());
        else
        {
            //找到第一个相比k颠倒的数字位置
            for(l = n - 1; l > k; l--)
            {
                if(nums[l] > nums[k])
                    break;
            }
            swap(nums[k],nums[l]);
            
            //翻转后面的东西
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};