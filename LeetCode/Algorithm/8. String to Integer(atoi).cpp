#include<iostream>
#include<string>
using namespace std;

class Solution
{
  public:
    static int myAtoi(string str)
    {
        int blank = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
                continue;
            else if (str[i] == '\0')
            {
                return 0;
            }
            else
            {
                blank = i;
                break;
            }
        }
        int sign = 1;
        if (str[blank] == '-')
        {
            sign = -1;
            blank++;
        }
        else if(str[blank]=='+')
        {
            blank++;
        }
        long long answer = 0;
        for (int i = blank; i < str.length(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                answer *= 10;
                answer += (str[i] - '0');
                if (answer > INT_MAX && sign == 1)
                    return INT_MAX;
                else if (answer > INT_MAX && sign == -1)
                    return INT_MIN;
            }
            else
                break;
        }
        return answer*sign;
    }
};