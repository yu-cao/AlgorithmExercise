class Solution {
public:
    static int reverse(int x) {
        int sign=1;
        if(x<0)
        {
            sign = -1;
            x *= -1;
        }
        if(x<0) return 0;
        long long res=0;
        for(;x!=0;)
        {
            res*=10;
            int temp=x%10;
            x/=10;
            res+=temp;
            if(res>2147483648)
            {
                return 0;//2^31==2 147 483 648,check it ahead.
            } 
        }
        return sign*res;
    }
};