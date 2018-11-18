class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0;i < s.length();i++)
        {
            for(int j = s.length() - 1;j >= i;j--)
            {
                if(s[i] == s[j])
                {
                    int k = i;
                    int l = j;
                    for(; k <= l;l--,k++)
                    {
                        if(s[k]!=s[l])
                            break;
                    }
                    if(k>=l)
                    {
                        if(j - i + 1 >= ans.length())
                        {
                            ans = "";
                            for(int m = i;m <= j;m++)
                            {
                                ans += s[m];
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
