class Solution {
public:
    static bool isPalindrome(int x) {
        long long first = x;
        if(first<0) return false;
        const long long fin = first;
        long long next=0;
        for(int i=0;first!=0;i++)
        {
            next*=10;
            int temp = first%10;
            first/=10;
            next+=temp;
        }
        if(next==fin) return true;
        else return false;
    }
};