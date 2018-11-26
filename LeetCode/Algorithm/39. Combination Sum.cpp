#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        int num = 0;

        int count[candidates.size()];//The count of the answer

        //TO BE USED
        int delta[candidates.size()-1];//The delta value of right element

        memset(count, 0, sizeof(int) * candidates.size());

        for (;; count[0]++)
        {
            if (count[0] * candidates[0] >= target) break;
        }

        for (;;)
        {
            int flag = false;

            //Calculate the result to compare with target
            int s = 0;
            for (int i = 0; i < candidates.size(); i++)
            {
                s += count[i] * candidates[i];
            }

            //Print answer
            if (s == target)
            {
                for (int i = 0; i < candidates.size(); i++)
                {
                    for (int j = 0; j < count[i]; j++)
                    {
                        ans[num].push_back(candidates[i]);
                    }
                }
            }
            else if (s < target)
            {
                //TODO



            }
            else if(s > target)
            {
                //TODO


            }


            //Loop break condition
            for (int i = 0; i < candidates.size() - 1; i++)
            {
                if (count[i] != 0)
                    flag = true;
            }

            if (flag == 0)
                break;
        }

    }


};

int main()
{
    Solution ans;
    vector<int> a = {2, 3, 6, 7};
    int target = 15;

    vector<vector<int>> judge = ans.combinationSum(a, 15);

    cout << judge.size();
}

