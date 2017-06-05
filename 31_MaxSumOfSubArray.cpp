#include <iostream>
#define LENGTH 8

using namespace std;

int getMaxSum(int nums[], int len)
{
    if(nums==NULL || len<=0)
        return 0;
    int maxSum = 0;
    int conSum = 0;
    for(int i=0;i<len;i++)
    {
        if(conSum<0)
            conSum = nums[i];
        else
            conSum += nums[i];

        if(maxSum<conSum)
            maxSum = conSum;
    }

    return maxSum;
}

int main()
{
    int nums[LENGTH] = {1,-2,3,10,-4,7,2,-5};
    int sum = getMaxSum(nums,LENGTH);
    cout << sum << endl;

    return 0;
}
