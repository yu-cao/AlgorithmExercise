//in Chinese
//1. 归纳基础：1
//2. 因为一个1，所以是11
//3. 因为两个1，所以是21
//4. 因为一个2，一个1，所以是1211
// ...
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1) return "1";

        string s = countAndSay(n - 1);
        string str;
        int len = 1, i = 0;
        for (; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
                len++;
            else
            {
                str.append(1,len + '0');
                str.append(1,s[i]);
                len = 1;
            }
        }
        str.append(1,len + '0');
        str.append(1,s[i]);
        return str;
    }
};