class Solution
{
public:
    double ans = 0;
    double myPow(double x, int n)
    {
        if (n == 0) return 1;
        else if (n == 1) return x;
        else if (n == -1) return 1.0 / x;
        else
        {
            ans = myPow(x,n/2);
            if (n % 2 == 1)
            {
                return ans * ans * x;
            }
            else if (n % 2 == -1)
            {
                return ans * ans / x;
            }
            else return ans * ans;
        }
    }
};
