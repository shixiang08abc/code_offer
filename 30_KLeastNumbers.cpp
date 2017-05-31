#include <iostream>
#define LENGTH 8

using namespace std;

int getPartition(int nums[], int pStart, int pEnd)
{
    int base = nums[pStart];
    while(pStart<pEnd)
    {
        while(nums[pEnd]>=base && pEnd>pStart)
            pEnd--;
        nums[pStart] = nums[pEnd];
        while(nums[pStart]<=base && pStart<pEnd)
            pStart++;
        nums[pEnd] = nums[pStart];
    }
    nums[pStart] = base;

    return pStart;
}

void getLeastNumbers(int nums[], int len, int k)
{
    if(nums==NULL || k>=len || len<=0 || k<=0)
        return;
    int pStart = 0;
    int pEnd = len - 1;
    int index = getPartition(nums,pStart,pEnd);
    while(index!=k-1)
    {
        if(index<k-1)
        {
            pStart = index + 1;
            index = getPartition(nums,pStart,pEnd);
        }
        else
        {
            pEnd = index - 1;
            index = getPartition(nums,pStart,pEnd);
        }
    }
}

int main()
{
    int nums[LENGTH] = {4,5,1,6,2,3,7,8};
    getLeastNumbers(nums,LENGTH,4);

    cout << "sort result:";
    for(int i=0;i<LENGTH;i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
