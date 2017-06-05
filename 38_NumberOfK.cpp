#include <iostream>
#define LENGTH 8

using namespace std;

int getFirstIndex(int nums[], int len, int k, int pstart, int pend)
{
    if(nums==NULL || pstart>pend)
        return -1;
    int mid = (pstart + pend)/2;
    if(nums[mid]==k)
    {
        if(mid-1>=0 && nums[mid-1]!=k)
            return mid;
        else
            pend = mid - 1;
    }
    else if(nums[mid]>k)
        pend = mid - 1;
    else
        pstart = mid + 1;

    return getFirstIndex(nums,len,k,pstart,pend);
}

int getEndIndex(int nums[],int len, int k, int pstart, int pend)
{
    if(nums==NULL || pstart>pend)
        return -1;
    int mid = (pstart + pend)/2;
    if(nums[mid]==k)
    {
        if(mid+1<=len-1 && nums[mid+1]!=k)
            return mid;
        else
            pstart = mid + 1;
    }
    else if(nums[mid]>k)
        pend = mid - 1;
    else
        pstart = mid + 1;

    return getEndIndex(nums,len,k,pstart,pend);
}

int getNumberOfK(int nums[], int len, int k)
{
    if(nums==NULL || len<=0)
        return -1;
    int firstIdx = getFirstIndex(nums,len,k,0,len-1);
    int endIdx = getEndIndex(nums,len,k,0,len-1);
    int number = -1;
    if(firstIdx!=-1 && endIdx!=-1 && firstIdx<endIdx)
        number = endIdx - firstIdx + 1;

    return number;
}

int main()
{
    int nums[LENGTH] = {1,2,3,3,3,3,4,5};
    int nlength = getNumberOfK(nums,LENGTH,3);
    cout << nlength << endl;

    return 0;
}
