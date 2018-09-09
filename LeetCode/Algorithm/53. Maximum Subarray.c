#include<stdio.h>
int max(int a,int b,int c)
{
    if(a >= b)
    {
        if(a >= c) return a;
        else return c;
    }
    else
    {
        if(b >= c) return b;
        else return c;
    }
}

int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 1)
        return nums[0];
    int mid = numsSize / 2;
    int maxLeft = maxSubArray(nums,mid);
    int maxRight = maxSubArray(&nums[mid],numsSize - mid);
    int temp = 0, leftSum = 0, rightSum = 0;
    for(int i = mid - 1; i>= 0; --i)
    {
        temp += nums[i];
        if(temp > leftSum) leftSum = temp;
    }
    temp = 0;
    for(int i = mid + 1; i < numsSize; ++i)
    {
        temp += nums[i];
        if(temp > rightSum) rightSum = temp;
    }
    return max(maxLeft,maxRight,leftSum + rightSum + nums[mid]);
}

int main(int argc, char const *argv[])
{
    int a[2] = {-2,1};
    int size = 2;
    printf("%d",maxSubArray(a,size));
    return 0;
}
