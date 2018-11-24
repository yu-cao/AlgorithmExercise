class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto i = nums.begin();i!= nums.end() && i!=nums.end()-1;)
            if(*i == *(i+1))
                nums.erase(i+1);     
            else i++;
        return nums.size();
    }
};