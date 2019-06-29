class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int max = 0, min = 255, num = 0, mode_i,mode_num = 0;
        double sum = 0;
        bool flag = true;
        for(int i = 0; i < count.size(); i++)
        {
            if(count[i]!=0)
            {
                if(max < i)
                {
                    max = i;
                }
                if(min > i)
                {
                    min = i;
                }
                num+= count[i];
                if(count[i]>mode_num)
                {
                    mode_i = i;
                    mode_num = count[i];
                }
                sum+=count[i]*i;
            }
        }
        int changdu = num;
        //找中位数，总数为num 4ge 1 1 2 2 -> 1.5
        double mid = 0;
        num /= 2;
        for(int i = 0; i<count.size()-1;i++)
        {
            if(num > count[i])
            {
                num -= count[i];
                continue;
            }
            if(num < count[i])
            {
                mid = i;
                break;
            }
            if(num == count[i] && changdu % 2 == 1)
            {
                mid = i + 1;
                break;
            }
            else if(num == count[i] && changdu %2 == 0)
            {
                mid = i + 0.5;
                break;
            }
        }
        return vector<double>{min, max,sum/changdu,mid,mode_i};
    }
};