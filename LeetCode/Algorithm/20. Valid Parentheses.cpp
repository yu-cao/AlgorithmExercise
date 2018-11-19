class Solution {
public:
    bool isValid(string s) {
        if(s == "") return true;
        int stack[s.length()];
        long long point = 0;
        bool flag = true;
        
        for(auto i = 0; i < s.length();i++)
        {
            if(s[i] == '(')
                stack[point++] = 1;
            else if(s[i] == '[')
                stack[point++] = 2;
            else if(s[i] == '{')
                stack[point++] = 3;
            else if(point == 0 && (s[i] == ')' || s[i] == ']' || s[i] == '}')) 
                return false;
            else if(s[i] == ')')
            {
                if(stack[point-1] == 1)
                    stack[--point] = 0;
                else
                {
                    flag = false;
                    break;
                }
            }
            else if(s[i] == ']')
            {
                if(stack[point-1] == 2)
                    stack[--point] = 0;
                else
                {
                    flag = false;
                    break;
                }
            }
            else if(s[i] == '}')
            {
                if(stack[point-1] == 3)
                    stack[--point] = 0;
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if(stack[0] != 0)
            return false;
        return flag;
    }
};
