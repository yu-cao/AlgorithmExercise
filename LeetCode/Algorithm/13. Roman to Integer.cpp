class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.length();)
        {
            if (s[i] == 'M')//>=1000
            {
                ans += 1000;
                i++;
            }
            else if (s[i] == 'D')//>=500 && < 900
            {
                if (s[i + 1] == 'C')//>=600 && < 900
                {
                    if (s[i + 2] == 'C')//>=700 && < 900
                    {
                        if (s[i + 3] == 'C')//>= 800 && < 900
                        {
                            ans += 800;
                            i = i + 4;
                        }
                        else
                        {
                            ans += 700;
                            i = i + 3;
                        }
                    }
                    else
                    {
                        ans += 600;
                        i = i + 2;
                    }
                }
                else
                {
                    ans += 500;
                    i++;
                }
            }
            else if (s[i] == 'C')
            {
                if (s[i + 1] == 'M')//>=900 && < 1000
                {
                    ans += 900;
                    i = i + 2;
                }
                else if (s[i + 1] == 'D')//>=400 && < 500
                {
                    ans += 400;
                    i = i + 2;
                }
                else if (s[i + 1] == 'C')//>=200 && < 400
                {
                    if (s[i + 2] == 'C')//>=300 && < 400
                    {
                        ans += 300;
                        i = i + 3;
                    }
                    else
                    {
                        ans += 200;
                        i = i + 2;
                    }
                }
                else//>=100 && < 200
                {
                    ans += 100;
                    i++;
                }
            }
            else if (s[i] == 'L')//>=50 && < 90
            {
                if (s[i + 1] == 'X')//>=60 && < 90
                {
                    if (s[i + 2] == 'X')//>=70 && < 90
                    {
                        if (s[i + 3] == 'X')//>=80 && < 90
                        {
                            ans += 80;
                            i = i + 4;
                        }
                        else
                        {
                            ans += 70;
                            i = i + 3;
                        }
                    }
                    else
                    {
                        ans += 60;
                        i = i + 2;
                    }
                }
                else
                {
                    ans += 50;
                    i++;
                }
            }
            else if (s[i] == 'X')
            {
                if (s[i + 1] == 'C')//>=90 && < 100
                {
                    ans += 90;
                    i = i + 2;
                }
                else if (s[i + 1] == 'L')//>= 40 && < 50
                {
                    ans += 40;
                    i = i + 2;
                }
                else if (s[i + 1] == 'X')//>= 20 && < 40
                {
                    if (s[i + 2] == 'X')//>= 30 && < 40
                    {
                        ans += 30;
                        i = i + 3;
                    }
                    else
                    {
                        ans += 20;
                        i = i + 2;
                    }
                }
                else//>= 10 && < 20
                {
                    ans += 10;
                    i++;
                }
            }
            else if (s[i] == 'V')
            {
                if (s[i + 1] == 'I')// == 6
                {
                    if (s[i + 2] == 'I')// == 7
                    {
                        if (s[i + 3] == 'I')// == 8
                        {
                            ans += 8;
                            i = i + 4;
                        }
                        else
                        {
                            ans += 7;
                            i = i + 3;
                        }
                    }
                    else
                    {
                        ans += 6;
                        i = i + 2;
                    }
                }
                else// == 5
                {
                    ans += 5;
                    i++;
                }
            }
            else if (s[i] == 'I')
            {
                if (s[i + 1] == 'V')// == 4
                {
                    ans += 4;
                    i = i + 2;
                }
                else if (s[i + 1] == 'X')// == 9
                {
                    ans += 9;
                    i = i + 2;
                }
                else if (s[i + 1] == 'I')// == 2
                {
                    if (s[i + 2] == 'I')// == 3
                    {
                        ans += 3;
                        i = i + 3;
                    }
                    else
                    {
                        ans += 2;
                        i = i + 2;
                    }
                }
                else// == 1
                {
                    ans++;
                    i++;
                }
            }
        }
        return ans;
    }
};
