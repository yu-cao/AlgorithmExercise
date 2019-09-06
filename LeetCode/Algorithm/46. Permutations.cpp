class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        permuteRecursive(nums, 0, ans);
        
        return ans;
    }
    
    void permuteRecursive(vector<int>& num, int begin, vector<vector<int>>& ans)
    {
        if (begin >= num.size()) {
		    ans.push_back(num);
		    return;
		}
		
        //适当进行全排列设计
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, ans);
		    swap(num[begin], num[i]);// reset
		}
    }
};