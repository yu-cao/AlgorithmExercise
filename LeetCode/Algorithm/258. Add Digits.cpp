class Solution {
public:
    int addDigits(int num) {
        int temp=num;
        for(int i=0;temp/10!=0;i++){
            num=temp;
            temp=0;
            for(int j=0;num!=0;j++){
                temp+=num%10;
                num/=10;
            }
        }
        return temp;
    }
};

