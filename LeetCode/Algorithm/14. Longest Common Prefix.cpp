class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestString = "";
        if(strs.empty())
            return longestString;
        for(auto i = 0; i < strs[0].length();i++)
        {
            for(auto j = 0; j < strs.size();j++)
            {
                if(strs[0][i]!=strs[j][i])
                    return longestString;
            }
            longestString += strs[0][i];
        }
        return longestString;
    }
};
