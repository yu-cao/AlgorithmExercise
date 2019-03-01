//二分法暴力求解
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        if(nums.empty()) return ans;
        
        int begin = 0,end = nums.size() - 1;
        //搜左边
        while(begin < end)
        {
            int mid = (end - begin) / 2 + begin;
            if(nums[mid] < target) begin = mid+1;
            else end = mid;
        }
        if(nums[begin] == target) ans[0] = begin;
        else return ans;
        
        begin = 0; end = nums.size() - 1;
        while(begin < end)
        {
            int mid = (end - begin) / 2 + begin + 1;
            if(nums[mid] > target) end = mid - 1;
            else begin = mid;
        }  
        ans[1] = end;//左侧合法，右侧必然合法
        return ans;
    }
};