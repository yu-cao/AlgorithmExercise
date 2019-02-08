class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if(digits.empty()) return vector<string>();
		vector<string> ans = {""};//初始化要为一个空字符串以方便for的k，空vector无法进入push_back
		vector<string> map_num = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		for(int i = 0;i < digits.size();i++)
		{
			int num = digits[i]-'0';
			string candidate = map_num[num];
			if(candidate.empty()) continue;
            //回溯法，FIFO策略
			vector<string> tmp;
			for(int j = 0;j < candidate.size();j++)
			{
				for(int k = 0;k < ans.size();k++)
				{
					tmp.push_back(ans[k]+candidate[j]);
				}
			}
			ans.swap(tmp);
		}
		return ans;
	}
};
