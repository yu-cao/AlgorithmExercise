//Notice: this two type must be the same "int"
//Never operater the signed number and the unsigned number!
//Especially in the loop condition!
class Solution {
public:
    int strStr(string haystack, string needle) {
        int length_a = haystack.length(),length_b = needle.length();
        if(needle == "") return 0;
        if(haystack == "") return -1;
        
        for(int i = 0; i <= length_a - length_b;i++)
            if(haystack.compare(i,length_b,needle)==0)//First para is the location, second para is the length of substr to compare, third para is comparing string
                return i;
        return -1;
    }
};