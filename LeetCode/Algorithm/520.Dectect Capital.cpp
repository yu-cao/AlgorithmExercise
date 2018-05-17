#include <string>
using namespace std;

class Solution
{
  public:
    bool detectCapitalUse(string word)
    {
        int flag = 0;
        if (word.front() >= 'A' && word.front() <= 'Z')
        {
            if (word[1] >= 'A' && word[1] <= 'Z')
            {
                for (int i = 1; i < word.length(); i++)
                {
                    if (word[i] < 'A' || word[i] > 'Z')
                        flag = 1;
                }
            }
            else if (word[1] >= 'a' && word[1] <= 'z')
            {
                for (int i = 1; i < word.length(); i++)
                {
                    if (word[i] < 'a' || word[i] > 'z')
                        flag = 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] < 'a' || word[i] > 'z')
                    flag = 1;
            }
        }
        if (flag == 1)
            return false;
        else
            return true;
    }
};