#include <iostream>
#define LENGTH 4

using namespace std;

int inversePairs(int nums[], int cpnums[], int pstart, int pend)
{
    if(pstart==pend)
        return 0;
    int mid = (pstart + pend)/2;
    int left = inversePairs(nums,cpnums,pstart,mid);
    int right = inversePairs(nums,cpnums,mid+1,pend);
    int idx = pend;
    int cnt = 0;
    int i = mid;
    int j = pend;
    while(i>=pstart && j>=mid+1)
    {
        if(nums[i]>nums[j])
        {
            cnt += j - mid;
            cpnums[idx--] = nums[i--];
        }
        else
        {
            cpnums[idx--] = nums[j--];
        }
    }
    while(j>=mid+1)
        cpnums[idx--] = nums[j--];
    while(i>=pstart)
        cpnums[idx--] = nums[i--];

    for(int k=pstart;k<=pend;k++)
        nums[k] = cpnums[k];

    return cnt + left + right;
}

int inversePairs(int nums[], int len)
{
    if(nums==NULL || len<=1)
        return 0;
    int* cpnums = new int[len];
    for(int i=0;i<len;i++)
        cpnums[i] = nums[i];
    int cnt = inversePairs(nums,cpnums,0,len-1);

    return cnt;
}

int main()
{
    int nums[LENGTH] = {7,5,6,4};
    int cnt = inversePairs(nums,LENGTH);
    cout << cnt << endl;

    return 0;
}
