int lengthOfLongestSubstring(char *s)
{
    int i, j;
    int max = 0;
    for (i = 0; i < strlen(s); i++)
    {
        int asc[128] = {0};//like bucket sort in using ASCII to decrease time complexity.
        asc[s[i]] = 1;
        //int count = i +128;
        if (strlen(s) > (i + 130))
            for (j = i + 1; j < i + 130; j++)
                if (asc[s[j]] == 1) break;
                else asc[s[j]] = 1;
        else
            for (j = i + 1; j < strlen(s); j++)
                if (asc[s[j]] == 1) break;
                else asc[s[j]] = 1;
        if (j - i > max)
            max = j - i;
        if(max == 95) break;//The max is the sum of ASCII without hiding code(like \b etc.), otherwise the loop will cause TLE
    }
    return max;
}
