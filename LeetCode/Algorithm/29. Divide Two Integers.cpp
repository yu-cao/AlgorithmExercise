//Without using multiplication, division and mod operator.
//Too slow!
//Advance modification Ref: https://leetcode.com/problems/divide-two-integers/discuss/13420/32-times-bit-shift-operation-in-C-with-O(1)-solution
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int64_t dived = dividend,divor = divisor;
        if(dividend < 0)
            dived = dividend * -1.0;
        if(divisor < 0)
            divor = divisor * -1.0;

        int64_t remainder = dived;
        int64_t quotient = 0;

        if(divor != 1)
            while (remainder >= divor)
            {
                remainder = remainder - divor;
                quotient++;
            }
        else
            quotient = remainder;

        if((dividend ^ divisor) < 0)
            quotient = -quotient;

        if(quotient > 2147483647 || quotient < -2147483648)
            return 2147483647;

        return quotient;
    }
};