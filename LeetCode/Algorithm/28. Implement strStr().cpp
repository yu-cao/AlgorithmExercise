class Solution {
public:
    int strStr(string haystack, string needle) {
        int length_a = haystack.length(),length_b = needle.length();
        if(needle == "") return 0;
        if(haystack == "") return -1;
        
        for(int i = 0; i <= length_a - length_b;i++)
            if(haystack.compare(i,length_b,needle)==0)
                return i;
        return -1;
    }
};