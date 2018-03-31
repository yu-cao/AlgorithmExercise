#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    static vector<int> plusOne(vector<int>& digits) {
        int length=digits.size();
        digits[length-1]++;
        if(digits[length-1]==10){
            for(int i=digits.size()-1;i>=0;i--){
                if(digits[i]==10){
                    if(i==0){
                        digits[i]=0;
                        vector<int> res ={1};
                        for(int i=0;i<digits.size();i++){
                            res.push_back(digits[i]);
                        }
                        return res;
                    }
                    else
                        digits[i-1]++;
                        digits[i]=0;
                }
            }
        }
        return digits;
    }
};

int main(void)
{
    vector<int> digits = {9,9};
    vector<int> hello;
    hello=Solution::plusOne(digits);
    for(int i=0;i<hello.size();i++){
        cout<<hello[i]<<endl;
    }
    return 0;
}
//give an array and plus one