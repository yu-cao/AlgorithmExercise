#include<vector>
using namespace std;

#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,i=0,j=height.size()-1;
        while(i<j)
        {
            ans=max(ans,(j-i)*min(height[i],height[j]));
            (height[i]>height[j])?j--:i++;
        }
        return ans;
    }
};