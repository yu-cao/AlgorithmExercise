class Solution {
public:
    string intToRoman(int num) {
        string str = "";
        for(;;)
        {
            if(num >= 1000)//With "M"
            {
                str += "M";
                num -= 1000;
            }
            else if(num >= 900 && num < 1000)//With "M"
            {
                str += "CM";
                num -= 900;
            }
            else if(num >= 400 && num < 900)//With "D"
            {
                if(num >= 800)
                {
                    str += "DCCC";
                    num -= 800;
                }
                else if(num >= 700)
                {
                    str += "DCC";
                    num -= 700;
                }
                else if(num >= 600)
                {
                    str += "DC";
                    num -= 600;
                }
                else if(num >= 500)
                {
                    str += "D";
                    num -= 500;
                }
                else
                {
                    str += "CD";
                    num -= 400;
                }
            }
            else if(num >= 90 && num < 400)//With "C"
            {
                if(num >= 300)
                {
                    str += "CCC";
                    num -= 300;
                }
                else if(num >= 200)
                {
                    str += "CC";
                    num -= 200;
                }
                else if(num >= 100)
                {
                    str += "C";
                    num -= 100;
                }
                else
                {
                    str += "XC";
                    num -= 90;
                }
            }
            else if(num >= 40 && num < 90)//With "L"
            {
                if(num >= 80)
                {
                    str += "LXXX";
                    num -= 80;
                }
                else if(num >= 70)
                {
                    str += "LXX";
                    num -= 70;
                }
                else if(num >= 60)
                {
                    str += "LX";
                    num -= 60;
                }
                else if(num >= 50)
                {
                    str += "L";
                    num -= 50;
                }
                else
                {
                    str += "XL";
                    num -= 40;
                }
            }
            else if(num >= 9 && num < 40)//With "X"
            {
                if(num >= 30)
                {
                    str += "XXX";
                    num -= 30;
                }
                else if(num >= 20)
                {
                    str += "XX";
                    num -= 20;
                }
                else if(num >= 10)
                {
                    str += "X";
                    num -= 10;
                }
                else
                {
                    str += "IX";
                    num -= 9;
                }
            }
            else if(num >=4 && num < 9)//With "V"
            {
                if(num >= 8)
                {
                    str += "VIII";
                    num -= 8;
                }
                else if(num >= 7)
                {
                    str += "VII";
                    num -= 7;
                }
                else if(num >= 6)
                {
                    str += "VI";
                    num -= 6;
                }
                else if(num >= 5)
                {
                    str += "V";
                    num -= 5;
                }
                else
                {
                    str += "IV";
                    num -= 4;
                }
            }
            else if(num >= 1 && num <= 3)//With "I"
            {
                if(num == 3)
                {
                    str += "III";
                    num -= 3;
                }
                if(num == 2) 
                {
                    str += "II";
                    num -= 2;
                }
                if(num == 1)
                {
                    str += "I";
                    num -= 1;
                }
            }
            else return str;
        }
    }
};
