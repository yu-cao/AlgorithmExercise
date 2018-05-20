#include <iostream>
using namespace std;

class Solution
{
  public:
    char findTheDifference(string s, string t)
    {
        char alpha[26] = {0};
        char beta[26] = {0};

        for (int i = 0; i < s.length(); i++)
            alpha[s[i] - 'a']++;

        for (int i = 0; i < t.length(); i++)
            beta[t[i] - 'a']++;

        for (int i = 0; i < 26; i++)
            if (alpha[i] != beta[i])
                return (i + 'a');
    }
};