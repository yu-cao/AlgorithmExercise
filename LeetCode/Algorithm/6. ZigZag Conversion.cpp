//Key: the skip is 2(row - i - 1) & 2i
class Solution
{
public:
    string convert(string s, int numRows)
    {
        string ans = "";

        for (int i = 0; i < numRows; i++)
        {
            int skip1 = 2 * (numRows - i - 1);
            int skip2 = 2 * i;
            bool first = true;
            for (int j = i;;)
            {
                if (first)
                {
                    ans += s[j];
                    first = false;
                }
                if (skip1 != 0)
                {
                    j += skip1;
                    if (j >= s.length()) break;
                    ans += s[j];
                }
                if (skip2 != 0)
                {
                    j += skip2;
                    if (j >= s.length()) break;
                    ans += s[j];
                }
                if (skip1 == 0 && skip2 == 0) return s;
            }
        }
        return ans;
    }
};
